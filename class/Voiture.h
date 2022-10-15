#ifndef VOITURE_H
#define VOITURE_H

#include "Modele.h"
#include "Option.h"
class Voiture
{
private:
  std::string nom;
  Modele modele;
  Option* options[5];

public:
  //constructeur
  Voiture();
  Voiture(std::string nom, Modele modele);
  Voiture(const Voiture& p);
  //destructeur
  ~Voiture();
  // getteur
  std::string getNom() const ;
  Modele getModele() const ;
  Option * getOption(int i) const;
  //setteur
  void setNom(std::string s);
  void setModele(const Modele& m);
  void setOption( Option* o, int i);
  //fonctions
  void Affiche();
  void AjouteOption(const Option & option);
  void RetireOption(std::string code);
  float getPrix();
};

#endif