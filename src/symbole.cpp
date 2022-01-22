#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void OpenPar::Affiche() { Symbole::Affiche(); }
void ClosePar::Affiche() { Symbole::Affiche(); }
void Plus::Affiche() { Symbole::Affiche(); }
void Mult::Affiche() { Symbole::Affiche(); }
void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}
void Fin::Affiche() { Symbole::Affiche(); }
void Erreur::Affiche() { Symbole::Affiche(); }
void Expr::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

// getters
int Symbole::getValeur() { return -1; }
int Entier::getValeur() { return valeur; }
int Expr::getValeur() { return valeur; }
