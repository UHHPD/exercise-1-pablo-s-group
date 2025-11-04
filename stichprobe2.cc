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
    for (size_t i = 0; i < data.size()/N; i++) {
        
        double sum = 0.0;
        for (size_t j = 0; j < N; j++){
            sum += data[i*N + j];
        }
        
        double mean = sum / N;

        double var_sum = 0.0;
        for (size_t j = 0; j < N; j++) {
            double diff = data[i*N + j] - mean;
            var_sum += diff * diff;
        }
        double variance = var_sum / N;

        out_mean << mean << "\n";
        out_var << variance << "\n";
    }

    return 0;
}
