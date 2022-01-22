#include "etat.h"
#include <iostream>

// constantes
const int r2 = 3;
const int r3 = 3;
const int r4 = 3;
const int r5 = 1;

// Constructeurs
Etat::Etat() {}
Etat::~Etat() {}
Etat::Etat(string s) { name = s; }

int Etat::etat() { return -1; }
int Etat0::etat() { return 0; }
int Etat1::etat() { return 1; }
int Etat2::etat() { return 2; }
int Etat3::etat() { return 3; }
int Etat4::etat() { return 4; }
int Etat5::etat() { return 5; }
int Etat6::etat() { return 6; }
int Etat7::etat() { return 7; }
int Etat8::etat() { return 8; }
int Etat9::etat() { return 9; }

Etat0::Etat0() : Etat("Etat0") {}
Etat1::Etat1() : Etat("Etat1") {}
Etat2::Etat2() : Etat("Etat2") {}
Etat3::Etat3() : Etat("Etat3") {}
Etat4::Etat4() : Etat("Etat4") {}
Etat5::Etat5() : Etat("Etat5") {}
Etat6::Etat6() : Etat("Etat6") {}
Etat7::Etat7() : Etat("Etat7") {}
Etat8::Etat8() : Etat("Etat8") {}
Etat9::Etat9() : Etat("Etat9") {}

bool Etat0::transition(Automate &automate, Symbole *s) {
  switch (*s) {
  case INT:
    automate.decalage(s, new Etat3);
    break;
  case OPENPAR:
    automate.decalage(s, new Etat2);
    break;
  case EXPR:
    automate.decalage(s, new Etat1);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}
bool Etat1::transition (Automate & automate, Symbole * s){
    switch(*s){
        case PLUS:
            automate.decalage(s, new Etat4);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case FIN:
            return false;
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}
bool Etat2::transition (Automate & automate, Symbole * s){
    cout << "echo" << endl;
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.decalage(s, new Etat6);
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}
bool Etat3::transition (Automate & automate, Symbole * s){
    switch(*s){
        case PLUS:
            automate.reduction(r5, new Plus);
            break;
        case MULT:
            automate.reduction(r5, new Mult);
            break;
        case CLOSEPAR:
            automate.reduction(r5, new OpenPar);
            break;
        case FIN:
            automate.reduction(r5, new Fin);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}
bool Etat4::transition (Automate & automate, Symbole * s){
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.decalage(s, new Etat7);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}
bool Etat5::transition (Automate & automate, Symbole * s){
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.decalage(s, new Etat8);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}
bool Etat6::transition (Automate & automate, Symbole * s){
    switch(*s){
        case PLUS:
            automate.decalage(s, new Etat4);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new Etat9);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}
bool Etat7::transition (Automate & automate, Symbole * s){
    switch(*s){
        case PLUS:
            automate.reduction(r2, new Plus);
            break;
        case CLOSEPAR:
            automate.reduction(r2, new ClosePar);
            break;
        case FIN:
            automate.reduction(r2, new Fin);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}
bool Etat8::transition (Automate & automate, Symbole * s){
    switch(*s){
        case PLUS:
            automate.reduction(r3, new Plus);
            break;
        case CLOSEPAR:
            automate.reduction(r3, new ClosePar);
            break;
        case FIN:
            automate.reduction(r3, new Fin);
            break;
        case MULT:
            automate.reduction(r3, new Mult);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}
bool Etat9::transition (Automate & automate, Symbole * s){
    switch(*s){
        case PLUS:
            automate.reduction(r4, new Plus);
            break;
        case CLOSEPAR:
            automate.reduction(r4, new ClosePar);
            break;
        case FIN:
            automate.reduction(r4, new Fin);
            break;
        case MULT:
            automate.reduction(r4, new Mult);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}