#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream datei("daten.txt");
    
    if (!datei.is_open()) {
        std::cerr << "Fehler: Kann daten.txt nicht öffnen!" << std::endl;
        return 1;
    }
    
    int zahl1, zahl2;
    int summe = 0;
    int anzahl = 0;
    
    std::cout << "Lese Daten aus daten.txt..." << std::endl;
    
    while (datei >> zahl1 >> zahl2) {
        int paar_summe = zahl1 + zahl2;
        summe += paar_summe;
        anzahl++;
    }
    
    datei.close();
    
    std::cout << "Anzahl der Zahlenpaare: " << anzahl << std::endl;
    std::cout << "Gesamtsumme: " << summe << std::endl;
    
    if (anzahl > 0) {
        std::cout << "Durchschnitt: " << static_cast<double>(summe) / anzahl << std::endl;
    }
    
    return 0;
}
