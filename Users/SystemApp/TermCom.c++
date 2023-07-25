/*
For the guide go to: https://github.com/Croc-Prog-github/Xen-OS/blob/main/Documents/Guide/Usare%20TermCom.md
*/
#include <iostream>
#include <string>
using namespace std;

void NCom() {
    string com;
    std::cout << "comands: ";
    std::getline(std::cin, com);

    if (com.empty()) {
        NCom(); // Richiamo ricorsivo della funzione
    } else {
        // Utilizzo dello switch con le costanti enum per confrontare i comandi
        if (com == "system: shutdown") {
            // Esegui il comando di spegnimento
            std::cout << "Shutdown command executed" << endl;
        } else if (com == "system: restart") {
            // Esegui il comando di riavvio
            std::cout << "Restart command executed" << endl;
        } else if (com == "run_out:") {
            // Esegui il comando run_out
            std::cout << "Run out command executed" << endl;
        } else if (com == "setting: main") {
            // Esegui il comando setting: main
            std::cout << "Setting: main command executed" << endl;
        } else if (com == "setting: quit") {
            // Esegui il comando setting: quit
            std::cout << "Setting: quit command executed" << endl;
        } else {
            std::cout << "typing error" << endl;
            NCom(); // Richiamo ricorsivo della funzione
        }
    }
}

int main() {
    std::cout << "TermCom by Xen-OS" << endl;
    NCom();
    return 0;
}