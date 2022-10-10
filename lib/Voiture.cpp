#include <string>
#include <iostream>

#include "Voiture.h"
#include "Modele.h"

using namespace std;


//Constructeur
Voiture::Voiture()
{
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
  #endif
  nom = "Voiture sans nom";
  
}

Voiture::Voiture(std::string n, Modele m)
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif

  nom = n;
  setModele(m);


  
}
Voiture::Voiture(const Voiture& p)
{
  #ifdef DEBUG
  cout << "Contructeur de copie" << endl;
  #endif
  nom = p.nom;
  modele = p.modele;
  
}
//Destucteur
Voiture::~Voiture()
{
	#ifdef DEBUG
	cout << "Destructeur" << endl;
	#endif



}
//getX et SetX
std::string Voiture::getNom() const {return nom;}
Modele Voiture::getModele() const {return modele;}

void Voiture::setNom(std::string s) {nom = s;}
void Voiture::setModele(const Modele& m) 
{
  modele = m;
} 



//Fonctions
void Voiture::Affiche() // affiche le Voiture au terminal
{

	cout << "Nom voiture : " << nom << " Modele de la voiture : " << endl;
  modele.Affiche();
  
}