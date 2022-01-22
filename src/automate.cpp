#include "etat.h"
#include <iostream>
#include <stdio.h>

Automate::Automate(string flux) {
  this->lexer = new Lexer(flux);
  /*
  Symbole * s;
   while(*(s=this->lexer->Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      this->lexer->Avancer();
   }
   */
  Etat0 *depart = new Etat0();
  statestack.push(depart);
}

void Automate::run() {
  bool prochainEtat = true;

  while (prochainEtat) {
    Symbole *s = lexer->Consulter();
    lexer->Avancer();
    prochainEtat = statestack.top()->transition(*this, s);
  }
  if (*symbolstack.top() != ERREUR)
  {
    int resultat = symbolstack.top()->getValeur();
    cout << "Syntaxe correct" << endl << "Résultat : " << resultat << endl;
  } 
  else 
  {
    cout << "Syntaxe non reconnu : caractere invalide" << endl;
  }
}

void Automate::decalage(Symbole *s, Etat *e) {
  symbolstack.push(s);
  statestack.push(e);
}

void Automate::reduction(int n, Symbole *s) {
  stack<Symbole *> aEnlever;
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    delete (statestack.top());
    statestack.pop();
    aEnlever.push(symbolstack.top());
    symbolstack.pop();
  }

  int val;

  if (n == 1) {
    val = aEnlever.top()->getValeur();
  } else if (n == 3) {
    if (*aEnlever.top() == OPENPAR) {
      aEnlever.pop();
      val = aEnlever.top()->getValeur();
    } else {
      val = aEnlever.top()->getValeur();
      aEnlever.pop();
      if (*aEnlever.top() == MULT) {
        aEnlever.pop();
        val = val * aEnlever.top()->getValeur();
      } else {
        aEnlever.pop();
        val = val + aEnlever.top()->getValeur();
      }
    }
  }
  statestack.top()->transition(*this, new Expr(val));
  lexer->putSymbol(s);

}