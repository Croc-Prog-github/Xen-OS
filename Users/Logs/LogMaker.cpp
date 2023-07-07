#include <iostream>
#include <fstream>
using namespace std;

void MakeFile(const string& arg) {
    string filePath;

    if (arg == "1") {
        filePath = "/Users/Logs/SystemLogs/SystemLog.log";
    } else if (arg == "2") {
        filePath = "/Users/Logs/HardwareLogs/HardwareLog.log";
    } else {
        cout << "Errore nella funzione. Creazione del file non riuscita." <<endl;
        return;
    }

    std::ofstream file(filePath.c_str());

    if (file.is_open()) {
        file << "This is a sample file." <<endl;
        file.close();
        cout << "File creato in: " <<filePath <<endl;
    } else {
        cout << "Fallimento creazione file" <<endl;
    }
}