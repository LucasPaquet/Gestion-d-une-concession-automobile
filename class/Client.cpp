#include <string>
#include <iostream>

#include "Personne.h"
#include "Client.h"

//Constructeur
Client::Client() : Intervenant()
{
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
  #endif
  gsm = "0400/00.00.00";
}

Client::Client(string nom, string p, int n, string g) : Intervenant(nom,p,n)
{
  #ifdef DEBUG
  cout << "Contructeur par Initialisation" << endl;
  #endif
  gsm = g;
}

Client::Client(const Client& c)
{
  #ifdef DEBUG
  cout << "Contructeur de copie" << endl;
  #endif
  gsm = c.gsm;
  numero = c.numero;
  nom = c.nom;
  prenom = c.prenom;
  
}

//Destructeur 

Client::~Client()
{
  #ifdef DEBUG
  cout << "Destructeur" << endl;
  #endif
}

//setXXX et getXXX

void Client::setGsm(string g) {gsm = g;}
string Client::getGsm() const {return gsm;}

// operateur de surchages

Client& Client::operator=(const Client& c)
{
  gsm = c.gsm;
  numero = c.numero;
  nom = c.nom;
  prenom = c.prenom;

  return(*this);
}

ostream& operator<<(ostream& s,const Client& c)
{
  s << endl << "Nom    : " << c.getNom() << endl;
  s << "Prenom : " << c.getPrenom() << endl;
  s << "Numero : " << c.getNumero() << endl;
  s << "GSM : " << c.gsm << endl;
  return s;
}

// Fonction 

string Client::ToString() const
{
  string r;
  r = "[C" + to_string(getNumero()) + "] " + getNom() + " " + getPrenom();
  return r;
}

string Client::Tuple() const
{
  string r;
  r = to_string(getNumero()) + ";" + getNom() + ";" + getPrenom()+ ";" + getGsm();
  return r;
}