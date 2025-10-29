#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    const int N = 234;
    const int group_size = 9;
    const int num_groups = N / group_size;

    ifstream file("datensumme.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open 'datensumme.txt'." << endl;
        return 1;
    }

    vector<double> data;
    double value;
    while (file >> value) {
        data.push_back(value);
    }
    file.close();

    ofstream mean_out("mittelwerte.txt");
    ofstream var_out("varianzen.txt");
    if (!mean_out.is_open() || !var_out.is_open()) {
        cerr << "Error: Could not open output files." << endl;
        return 1;
    }

    vector<double> means;
    vector<double> variances;

    for (int g = 0; g < num_groups; ++g) {
        double sum = 0.0;
        for (int i = 0; i < group_size; ++i)
            sum += data[g * group_size + i];

        double mean = sum / group_size;
        means.push_back(mean);
        mean_out << mean << endl;

        double var_sum = 0.0;
        for (int i = 0; i < group_size; ++i) {
            double diff = data[g * group_size + i] - mean;
            var_sum += diff * diff;
        }

        double variance = var_sum / (group_size - 1); // Bessel’s correction
        variances.push_back(variance);
        var_out << variance << endl;
    }

    mean_out.close();
    var_out.close();

    double mean_of_means = 0.0;
    for (double m : means) mean_of_means += m;
    mean_of_means /= means.size();

    double mean_of_variances = 0.0;
    for (double v : variances) mean_of_variances += v;
    mean_of_variances /= variances.size();

    cout << mean_of_means << endl;
    cout << mean_of_variances << endl;

    return 0;
}
