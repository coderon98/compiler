#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      virtual int getValeur();
      virtual bool isTerminal(){return false;}
   protected:
      int ident;
};

class OpenPar: public Symbole {
   public: 
      OpenPar(): Symbole(Identificateurs::OPENPAR) {}
      virtual ~OpenPar() { }
      virtual void Affiche();
};
class ClosePar: public Symbole {
   public: 
      ClosePar(): Symbole(Identificateurs::CLOSEPAR) {}
      virtual ~ClosePar() { }
      virtual void Affiche();
      virtual bool isTerminal(){return true;}
};
class Plus: public Symbole {
   public: 
      Plus(): Symbole(Identificateurs::PLUS) {}
      virtual ~Plus() { }
      virtual void Affiche();
      virtual bool isTerminal(){return true;}
};
class Mult: public Symbole {
   public: 
      Mult(): Symbole(Identificateurs::MULT) {}
      virtual ~Mult() { }
      virtual void Affiche();
      virtual bool isTerminal(){return true;}
};
class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(Identificateurs::INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur();
      virtual bool isTerminal(){return true;}
   protected:
      int valeur;
};
class Fin: public Symbole {
   public: 
      Fin(): Symbole(Identificateurs::FIN) {}
      virtual ~Fin() { }
      virtual void Affiche();
      virtual bool isTerminal(){return true;}
};
class Erreur: public Symbole {
   public: 
      Erreur(): Symbole(Identificateurs::ERREUR) {}
      virtual ~Erreur() { }
      virtual void Affiche();
      virtual bool isTerminal(){return true;}
};
class Expr: public Symbole {
   public: 
      Expr(int v): Symbole(Identificateurs::EXPR), valeur(v) {}
      virtual ~Expr() { }
      virtual void Affiche();
      int getValeur();
      virtual bool isTerminal(){return false;}
   protected:
      int valeur;
};