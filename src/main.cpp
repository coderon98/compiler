#include <iostream>
#include "automate.h"

/*
int main(void) {
   string chaine("(1+34)*123");
   cout << chaine << endl;
   Lexer l(chaine);

   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }
   return 0;
}
*/

int main(void) {

  string chaine="(1+34)*123";
/*
  cout << "Indiquez la phrase à analyser :" << endl;
  cin >> chaine;
 */
  Automate *automate = new Automate(chaine);
  automate->run();

  return 0;
}
