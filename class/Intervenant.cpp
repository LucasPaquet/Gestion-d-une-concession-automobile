#include <string>
#include <iostream>

#include "Intervenant.h"


//Constructeur
Intervenant::Intervenant() : Personne()
{
  #ifdef DEBUG
  cout << "Contructeur par default de Intervenant" << endl;
  #endif
  numero = 0;
}

Intervenant::Intervenant(string nom, string prenom, int n) : Personne(nom, prenom)
{
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
  #endif
  numero = n;
}

Intervenant::Intervenant(const Intervenant& i)
{
  #ifdef DEBUG
  cout << "Contructeur de copie de Intervenant" << endl;
  #endif
  nom = i.nom;
  prenom = i.prenom;
  numero = i.numero;
  
}

//Destructeur 

Intervenant::~Intervenant()
{
  #ifdef DEBUG
  cout << "Destructeur de Intervenant" << endl;
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
  prenom = i.prenom;
  numero = i.numero;

  //copmleter avec la classes personnes

  return (*this); 
}

// Fonctions

void Intervenant::Save(ofstream & fichier) 
{
  #ifdef DEBUG
  cout << "Intervenant : Save" << endl;
  #endif

  Personne::Save(fichier);
  
  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }
  
  fichier.write((char*)&(*this).numero,sizeof(int)); // numero
}



void Intervenant::Load(ifstream & fichier)
{
  #ifdef DEBUG
  cout << "Intervenant : Load" << endl;
  #endif

  Personne::Load(fichier);

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }

  fichier.read((char*)&(*this).numero,sizeof(int)); // numero
}