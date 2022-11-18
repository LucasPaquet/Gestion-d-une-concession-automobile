#include <string>
#include <iostream>

#include "Intervenant.h"


//Constructeur
Intervenant::Intervenant() : Personne()
{
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
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
  cout << "Contructeur de copie" << endl;
  #endif
  nom = i.nom;
  prenom = i.prenom;
  numero = i.numero;
  
}

//Destructeur 

Intervenant::~Intervenant()
{
  #ifdef DEBUG
  cout << "Destructeur" << endl;
  #endif
  cout << "Destructeur de Intervenant" << endl;
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