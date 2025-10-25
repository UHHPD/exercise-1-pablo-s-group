#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ifstream datei("daten.txt");
  ofstream outfile("datensumme.txt");

  if (!datei.is_open()) {
    cerr << "Error: daten.txt cannot be opened!" << endl;
    return 1;
  }

  if (!outfile.is_open()) {
    cerr << "Error: datensumme.txt cannot be opened!" << endl;
    return 1;
  }

  double a, b;
  while (datei >> a >> b) {
    double sum = a + b;
    outfile << sum << endl;
  }

  datei.close();
  outfile.close();

  cout << "Summation complete. Results written to datensumme.txt" << endl;
  return 0;
}
