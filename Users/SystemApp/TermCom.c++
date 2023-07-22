/*
For the guide go to: https://github.com/Croc-Prog-github/Xen-OS/blob/main/Documents/Guide/Usare%20TermCom.md
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
  std::cout<<"TermCom by Xen-OS" <<endl;

  string com;
  std::getline(std::cin, com);

  if (com.empty()) {
    std::cout << "comands: ";
  } else {
    switch(com) {
      case 'system: shutdown':

      break;
      case 'system: restart':

      break;
      case 'run_out:':

      break;
      case 'setting: main':

      break;
      case 'setting: quit':

      break;

      default:
        std::cout << "typing error";
      break;
    }
  }
  
}