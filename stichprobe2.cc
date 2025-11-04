#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // Clear contents of output files
    ofstream("mittelwerte.txt", ios::trunc).close();
    ofstream("varianzen.txt", ios::trunc).close();

    ifstream input("datensumme.txt");
    ofstream out_mean("mittelwerte.txt");
    ofstream out_var("varianzen.txt");

    if (!input) {
        cerr << "Error: could not open datensumme.txt\n";
        return 1;
    }

    vector<double> data;
    double x;
    while (input >> x) data.push_back(x);

    const int N = 9;
    vector<double> means;
    vector<double> variances;
    for (size_t i = 0; i < data.size()/N; i++) {

        // Calculate means
        double sum = 0.0;
        for (size_t j = 0; j < N; j++){
            sum += data[i*N + j];
        }
        
        double mean = sum / N;

        // Calculate varinaces
        double var_sum = 0.0;
        for (size_t j = 0; j < N; j++) {
            double diff = data[i*N + j] - mean;
            var_sum += diff * diff;
        }
        double variance = var_sum / N;

        means.push_back(mean);
        variances.push_back(variance);
        out_mean << mean << "\n";
        out_var << variance << "\n";
    }

    size_t count = means.size();
    if (count >= 2) {
        // Mean of means
        double sum_means = 0.0;
        for (double m : means) sum_means += m;
        double mean_of_means = sum_means / count;

        // Variance of means with Bessel's correction
        double var_sum_means = 0.0;
        for (double m : means) var_sum_means += (m - mean_of_means) * (m - mean_of_means);
        double corrected_mean_of_variances = var_sum_means / (count - 1);

        // Mean of variances
        double sum_vars = 0.0;
        for (double v : variances) sum_vars += v;
        double mean_of_vars = sum_vars / count;

        // Variance of variances with Bessel's correction
        double var_sum_vars = 0.0;
        for (double v : variances) var_sum_vars += (v - mean_of_vars) * (v - mean_of_vars);
        double corrected_var_of_vars = var_sum_vars / (count - 1);

        // Output
        cout << mean_of_means << "\n";
        cout << corrected_mean_of_variances << "\n";
        cout << mean_of_vars << "\n";
        cout << corrected_var_of_vars << "\n";
    }
    

    return 0;
}
