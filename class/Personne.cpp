#include <string>
#include <iostream>

#include "Personne.h"

//Constructeur
Personne::Personne()
{
  #ifdef DEBUG
  cout << "Contructeur par default de Personne" << endl;
  #endif
  nom = "Sans nom";
  prenom = "Sans prenom";
}

Personne::Personne(string n,string p)
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation de Personne" << endl;
  #endif
  nom = n;
  prenom = p;
}

Personne::Personne(const Personne& p)
{
  #ifdef DEBUG
  cout << "Contructeur de copie de Personne" << endl;
  #endif
  nom = p.nom;
  prenom = p.prenom;
  
}
// Destructeur
Personne::~Personne()
{
  #ifdef DEBUG
  cout << "Destructeur de Personne" << endl;
  #endif
}

//getXXX et setXXX
string Personne::getNom() const {return nom;}
string Personne::getPrenom() const {return prenom;}
void Personne::setNom(string s) {nom = s;}
void Personne::setPrenom(string s) {prenom = s;}

// operateur de surchages

ostream& operator<<(ostream& s,const Personne& p)
{
  s << "Nom : "<< p.nom << endl << "Prenom : " << p.prenom << endl;
  return s;
}

istream& operator>>(istream& s, Personne& p)
{
  cout << "Nom : ";
  getline(s,p.nom);
  cout << "Prenom : ";
  getline(s,p.prenom);
  return s;
}

Personne& Personne::operator=(const Personne& p)
{

  #ifdef DEBUG
  cout << "Operateur de surcharges = " << endl;
  #endif

  nom = p.nom;
  prenom = p.prenom;

  return (*this); 
}

void Personne::Save(ofstream & fichier)
{
  #ifdef DEBUG
  cout << "Personne : Save" << endl;
  #endif

  int taille = (*this).nom.size();
  int tailleI = (*this).prenom.size();

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }

  fichier.write((char*)&taille,sizeof(int)); // on enregistre le nombre de caractere de nom
  fichier.write((char*)(*this).nom.data(),taille*sizeof(char));

  fichier.write((char*)&tailleI,sizeof(int)); // on enregistre le nombre de caractere de prenom
  fichier.write((char*)(*this).prenom.data(),tailleI*sizeof(char));
}

void Personne::Load(ifstream & fichier)
{
  #ifdef DEBUG
  cout << "Personne : Load" << endl;
  #endif

  int t;
  int t2;

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }
  fichier.read((char*)&t,sizeof(int)); // Lecture de nom
  (*this).nom.resize(t);
  fichier.read((char*)(*this).nom.data(),t*sizeof(char));
  

  fichier.read((char*)&t2,sizeof(int)); // Lecture de prenom
  (*this).prenom.resize(t2);
  fichier.read((char*)(*this).prenom.data(),t2*sizeof(char));

}



