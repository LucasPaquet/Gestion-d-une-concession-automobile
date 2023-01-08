#include <string>
#include <iostream>

#include "Personne.h"
#include "Client.h"

//Constructeur
Client::Client() : Intervenant()
{
  #ifdef DEBUG
  cout << "Contructeur par default de client " << endl;
  #endif
  gsm = "0400/00.00.00";
}

Client::Client(string nom, string p, int n, string g) : Intervenant(nom,p,n)
{
  #ifdef DEBUG
  cout << "Contructeur par Initialisation de client" << endl;
  #endif
  gsm = g;
}

Client::Client(const Client& c)
{
  #ifdef DEBUG
  cout << "Contructeur de copie de client" << endl;
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
  cout << "Destructeur de client" << endl;
  #endif
  cout << "Destructeur de Client" << endl;
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


void Client::Save(ofstream & fichier)
{
  #ifdef DEBUG
  cout << "Client : Save" << endl;
  #endif
  Intervenant::Save(fichier);

  int taille = (*this).gsm.size();

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }

  fichier.write((char*)&taille,sizeof(int)); // on enregistre le nombre de caractere de gsm
  fichier.write((char*)(*this).gsm.data(),taille*sizeof(char));
}


Client& Client::Load(ifstream & fichier)
{
  #ifdef DEBUG
  cout << "Client : Load" << endl;
  #endif

  Intervenant::Load(fichier);

  int t;

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }
  fichier.read((char*)&t,sizeof(int)); // Lecture de gsm
  (*this).gsm.resize(t);
  fichier.read((char*)(*this).gsm.data(),t*sizeof(char));

  return (*this);
}