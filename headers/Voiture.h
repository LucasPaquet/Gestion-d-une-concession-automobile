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
  //setteur
  //fonctions
  void Affiche();
};

#endif