#include <iostream>
using namespace std;

int main() {
    int n = 1;

    cout<<"1. Esci e continua su Xen-OS" <<endl;
    cout<<"2. Verifica Hardware" <<endl;
    cout<<"3. BIOS" <<endl;
    cout<<"4. Defrag Hardisk" <<endl;
    cout<<"5. Ripristina" <<endl;

    cin>>n;
    switch(n) {
        case 1:
            //
        break;
        case 2:
            cout<<"1. Verifica CPU (Processore)" <<endl;
            cout<<"2. Verifica GPU (Scheda Video)" <<endl;
            cout<<"3. Verifica Scheda Madre" <<endl;
        break;
        case 3:
            //
        break;
        case 4:
            //
        break;
        case 5:
            cout<<"1. Ripristina Xen-OS" <<endl;
            cout<<"2. Ripristina Hardisk" <<endl;
            cout<<"3. Ripristina Scheda Video" <<endl;
        break;
        default:
            cout<<"Numero non valido, riprova." <<endl;
            main();
        break;
    }
}