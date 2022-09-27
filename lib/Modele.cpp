#include <iostream>
#include <string.h>

#include "Modele.h"

using namespace std;

const int L_NOM = 60;


//Constructeur
Modele::Modele()
{
  nom = new char[L_NOM];
  strcpy(nom, "Voiture de malade");
  puissance = 100;
  moteur = Electrique;
  prixDeBase = 12500.0;
}

Modele::Modele(char * c, int i, Moteur m,float f)
{
  nom = new char[L_NOM];
  strcpy(nom,c);
  puissance = i;
  moteur = m;
  prixDeBase = f;
}
Modele::Modele(const Modele& p)
{
  nom = new char[L_NOM];
  strcpy(nom,p.nom);
  puissance = p.puissance;
  moteur = p.moteur;
  prixDeBase = p.prixDeBase;
}
//Destucteur
Modele::~Modele()
{
  cout << "Destructeur" << endl;
  if (nom) delete nom;
}
//getX et SetX
char * Modele::getNom() {return nom;}
int Modele::getPuissance() {return puissance;}
Moteur Modele::getMoteur() {return moteur;}
float Modele::getPrixDeBase() {return prixDeBase;}

void Modele::setNom(char * c) 
{
	nom = new char[L_NOM];
	strcpy(nom, c);
}
void Modele::setPuissance(int p) {puissance = p;}
void Modele::setMoteur(Moteur m) {moteur = m;}
void Modele::setPrixDeBase(float p) {prixDeBase = p;}
//Fonctions
void Modele::Affiche() // affiche le modele au terminal
{
  char * c;
  int i;
  Moteur m;
  float p;
  c = getNom();
  i = getPuissance();
  m = getMoteur();
  p = getPrixDeBase();
  cout << c << endl;
  cout << i << endl;
  cout << m << endl;
  cout << p << endl;
}
