#include <string>
#include <iostream>

#include "Voiture.h"
#include "Modele.h"

using namespace std;


//Constructeur
Voiture::Voiture()
{
  int i;
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
  #endif
  for(i=0;i<5;i++)
  {
    options[i] = NULL;
  }
  nom = "Voiture sans nom";
  
}

Voiture::Voiture(std::string n, Modele m)
{
  int i;
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif
  for(i=0;i<5;i++)
  {
    options[i] = NULL;
  }
  nom = n;
  setModele(m);
}
Voiture::Voiture(const Voiture& p)
{
  int i;
  Option* optionp=NULL,* optionso=NULL;

  #ifdef DEBUG
  cout << "Contructeur de copie" << endl;
  #endif

  for(i=0;i<5;i++)
  {
    optionp = p.getOption(i);
    if (optionp != NULL)
    {
      optionso = NULL;
      optionso = new Option[1];
      optionso->setCode(optionp->getCode());
      optionso->setIntitule(optionp->getIntitule());
      optionso->setPrix(optionp->getPrix());
      setOption(optionso, i);
    }
    else
    {
      options[i] =NULL;
    }
  }
  nom = p.nom;
  setModele(p.modele);
  
}
//Destucteur
Voiture::~Voiture()
{
  int i;
	#ifdef DEBUG
	cout << "Destructeur" << endl;
	#endif
  for(i=0;i<5;i++)
  {
    delete[] options[i];
  }

}
//getX et SetX
std::string Voiture::getNom() const {return nom;}
Modele Voiture::getModele() const {return modele;}
Option * Voiture::getOption(int i) const {return options[i];}

void Voiture::setNom(std::string s) {nom = s;}
void Voiture::setModele(const Modele& m) 
{
  modele.setNom(m.getNom());
  modele.setPuissance(m.getPuissance());
  modele.setMoteur(m.getMoteur());
  modele.setPrixDeBase(m.getPrixDeBase());
} 

void Voiture::setOption( Option* o, int i)
{
  options[i] = o;
}



//Fonctions
void Voiture::Affiche() // affiche le Voiture au terminal
{
  int i;
	cout << "Nom de la voiture voiture : " << nom << " Modele de la voiture : " << endl;
  modele.Affiche();
  for (i=0;i<5;i++)
  {
    if (options[i] != NULL)
    {
      cout << "Option n" << i << " : ";
      options[i]->Affiche();
    }
  }
  
}

void Voiture::AjouteOption(const Option & option) // ajoute une option a la voiture
{
  int i;
  Option * optionp = NULL;
  for (i=0;i<5;i++)
  {
    optionp = getOption(i);
    if (optionp == NULL)
    {
      optionp = new Option[1];
      optionp->setCode(option.getCode());
      optionp->setIntitule(option.getIntitule());
      optionp->setPrix(option.getPrix());
      break;
    }
  }
  setOption(optionp, i);
}

void Voiture::RetireOption(std::string code) // retire une option a la voiture
{
  int i;

  for (i=0;i<5;i++)
  {
    if (options[i]->getCode() == code)
    {
      delete[] options[i];
      options[i] = NULL;
      break;
    }
  }
}

float Voiture::getPrix()
{
  float prixTotal=0;
  int i;

  prixTotal = prixTotal + modele.getPrixDeBase();

  for (i=0;i<5;i++)
  {
    if (options[i] != NULL)
    {
      prixTotal = prixTotal + options[i]->getPrix();
    }
  }
  return prixTotal;
}