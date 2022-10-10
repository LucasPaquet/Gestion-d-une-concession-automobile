#ifndef VOITURE_H
#define VOITURE_H
#include <string>
#include "Modele.h"
class Voiture
{
private:
  std::string nom;
  Modele modele;

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
  //setteur
  void setNom(std::string s);
  void setModele(const Modele& m);
  //fonctions
  void Affiche();
};

#endif