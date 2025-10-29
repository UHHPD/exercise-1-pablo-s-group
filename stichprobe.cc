// Imports
#include <fstream>
#include <iostream>
#include <vector>
using namespace std; // Use the standard namespace to avoid using std::

int main() {
  const int N = 234;
  ifstream file("datensumme.txt"); // Open the file

  if (!file.is_open()) {
    cerr << "Error: Could not open file 'datensumme.txt'."
         << endl; // Error message if file cannot be opened
    return 1;
  }

  vector<double> numbers; // Vector to store the numbers
  double value;
  while (file >> value) {     // Read numbers from the file
    numbers.push_back(value); // Add the number to the vector
  }

  file.close();

  if (numbers.size() != N) {
    cerr << "Warning: Expected " << N << " numbers, but read " << numbers.size()
         << "." << endl;
  }

  double sum = 0.0;

  for (double x : numbers) { // Calculate the sum of the numbers
    sum += x;
  }

  double mean = sum / numbers.size(); // Calculate the mean

  std::cout << "Mean (ā) = " << mean << std::endl;

  return 0;
}