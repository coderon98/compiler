#include <iostream>
#include "automate.h"

int main(void) {

  string chaine;
  cout << "Indiquez la phrase à analyser :" << endl;
  cin >> chaine;
  
  Automate *automate = new Automate(chaine);
  automate->run();

  return 0;
}
