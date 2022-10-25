#include <iostream>
#include <string.h>

#include "Modele.h"

using namespace std;



//Constructeur

Modele::Modele()
{
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
  #endif
  nom =NULL;
  setNom("Voiture sans nom");
  puissance = 100;
  moteur = Electrique;
  prixDeBase = 12500.0;
}
Modele::Modele(const char * c, int i, Moteur m,float f)
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif
  nom=NULL;
  setNom(c);
  puissance = i;
  moteur = m;
  prixDeBase = f;
}
Modele::Modele(const Modele& p)
{
  #ifdef DEBUG
  cout << "Contructeur de copie" << endl;
  #endif
  nom =NULL;
  setNom(p.getNom());
  puissance = p.puissance;
  moteur = p.moteur;
  prixDeBase = p.prixDeBase;
}

//Destucteur

Modele::~Modele()
{
  #ifdef DEBUG
  cout << "Destructeur" << endl;
  this->Affiche();
  #endif
  if (nom)
    delete[] nom;

}

//getX et SetX

const char * Modele::getNom() const {return nom;}
int Modele::getPuissance() const {return puissance;}
Moteur Modele::getMoteur() const {return moteur;}
float Modele::getPrixDeBase() const {return prixDeBase;}

void Modele::setNom(const char * c) 
{
  if (c)
  {
    if (nom)
    {
      delete[] nom;  
    }
    
    nom = new char[strlen(c)+1];
    strcpy(nom, c);
  }
}
void Modele::setPuissance(int p) 
{
  if (p>=0)
    puissance = p;
}
void Modele::setMoteur(Moteur m) {moteur = m;}
void Modele::setPrixDeBase(float p) 
{
  if (prixDeBase >= 0)
    prixDeBase = p;
}

// operateur de surchages

ostream& operator<<(ostream& s,const Modele& m)
{
  s << "Nom : "<< m.nom << ", puissance : " << m.puissance << ", Prix de base : " << m.prixDeBase << ", Moteur : ";
  switch(m.moteur)
  {
    case Essence: s << "Essence" << endl;
      break;
    case Electrique: s << "Electrique" << endl;
      break;
    case Diesel: s << "Diesel" << endl;
      break;
    case Hybride: s << "Hybride" << endl;
      break;
  }
  
  return s;
}

istream& operator>> (istream& s, Modele& m)
{
  string buff;
  int moteurInt;
  cout << "Nom : ";
  getline(cin,buff);
  cout << "Puissance : ";
  s >> m.puissance;
  cout << "Prix de base : ";
  s >> m.prixDeBase;
  cout << "Moteur : ";
  s >> moteurInt;
  m.moteur = (Moteur)moteurInt;
  
  m.setNom(buff.data());
  return s;
}

//Fonctions

void Modele::Affiche() // affiche le modele au terminal
{
  cout << "Nom : "<< nom << ", puissance : " << puissance << ", Prix de base : " << prixDeBase << ", Moteur : ";
  switch(moteur)
  {
    case Essence: cout << "Essence" << endl;
      break;
    case Electrique: cout << "Electrique" << endl;
      break;
    case Diesel: cout << "Diesel" << endl;
      break;
    case Hybride: cout << "Hybride" << endl;
      break;
  }
}