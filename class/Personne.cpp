#include <string>
#include <iostream>

#include "Personne.h"

//Constructeur
Personne::Personne()
{
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
  #endif
  nom = "Sans nom";
  prenom = "Sans prenom";
}

Personne::Personne(string n,string p)
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif
  nom = n;
  prenom = p;
}

Personne::Personne(const Personne& p)
{
  #ifdef DEBUG
  cout << "Contructeur de copie" << endl;
  #endif
  nom = p.nom;
  prenom = p.prenom;
  
}
// Destructeur
Personne::~Personne()
{
	#ifdef DEBUG
	cout << "Destructeur" << endl;
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

//Fonctions 


// ---------- INTERVENANT ------------------

//Constructeur
Intervenant::Intervenant()
{
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
  #endif
  numero = 0;
}

//Constructeur
Intervenant::Intervenant(string nom, string prenom, int n) : Personne(nom, prenom)
{
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
  #endif
  numero = n;
}

//Destructeur 

Intervenant::~Intervenant()
{
  #ifdef DEBUG
  cout << "Destructeur" << endl;
  #endif
}

// SetXXX et getXXX

int Intervenant::getNumero() const {return numero;}
void Intervenant::setNumero(int n) {numero = n;}

// Surcharge des operateurs

Intervenant& Intervenant::operator=(const Intervenant& i)
{

  #ifdef DEBUG
  cout << "Operateur de surcharges = " << endl;
  #endif

  numero = i.numero;

  return (*this); 
}

//Fonctions




