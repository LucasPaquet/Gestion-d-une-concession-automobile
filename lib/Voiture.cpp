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

Voiture::Voiture(string nom, Modele modele)
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif
  
}
Voiture::Voiture(const Voiture& p)
{
  #ifdef DEBUG
  cout << "Contructeur de copie" << endl;
  #endif
  
}
//Destucteur
Voiture::~Voiture()
{
	#ifdef DEBUG
	cout << "Destructeur" << endl;
	#endif


}
//getX et SetX




//Fonctions
void Voiture::Affiche() // affiche le Voiture au terminal
{

	cout << "Nom : " << nom << " Modele de la voiture : " << endl;
  modele.Affiche();
  
}