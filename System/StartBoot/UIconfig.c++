#include <iostream>
using namespace std;

int main() {
  int r = 1;

  cout<<"Xen-OS" <<endl;
  cout<<"Scegli un'opzione:" <<endl;
  cout<<"1. Avvia configurazione" <<endl;
  cout<<"2. Opzioni avanzate" <<endl;
  cout<<"3. Terminale comandi" <<endl;

  cin>>r;
  std::cout << "\033[2J\033c";

  switch(r) {
    case 1:
      std::cout << "\033[2J\033c";
    break;
    case 2:
      std::cout << "\033[2J\033c";
    break;
    case 3:
      std::cout << "\033[2J\033c";
      
    break;
  }
}