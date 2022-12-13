#ifndef VOITURE_H
#define VOITURE_H

#include "Modele.h"
#include "Option.h"
#include "OptionException.h"


#include <string>
using namespace std;
class Voiture
{

  friend Voiture operator+(Option optionv, Voiture v); //pour v2 = op2 + v2;
  friend ostream& operator<<(ostream& s,Voiture& v);

private:
  string nom;
  Modele modele;
  Option* options[5];

public:
  //constructeur
  Voiture();
  Voiture(string nom,const Modele& modele);
  Voiture(const Voiture& p);

  //destructeur

  ~Voiture();

  // getteur

  string getNom() const ;
  Modele getModele() const ;
  Option * getOption(int i) const;

  //setteur

  void setNom(string s);
  void setModele(const Modele& m);
  void setOption( Option* o, int i);

  //surcharge des operateur

  Voiture& operator=(const Voiture& v);
  Voiture operator+(const Option & option);
  Voiture operator-(const Option & option);
  Voiture operator-(string code);
  int operator<(Voiture& v); 
  int operator>(Voiture& v); 
  int operator==(Voiture& v); 
  Option* operator[](int i);

  //fonctions

  void Affiche();
  void AjouteOption(const Option & option);
  void RetireOption(string code);
  float getPrix();

};

#endif