#include <string>
#include <iostream>

#include "Contrat.h"

//Constructeur
Contrat::Contrat()
{
  #ifdef DEBUG
  cout << "Contructeur par default de OptionException" << endl;
  #endif
}

Contrat::Contrat(int num, string ven, string c,string v) 
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation de Contrat : " << endl;
  #endif

  numero = num;
  vendeur = ven;
  client = c;
  voiture = v;
}

Contrat::Contrat(const Contrat& e)
{
  #ifdef DEBUG
  cout << "Contructeur de copie de Contrat : " << e.message <<endl;
  #endif
  numero = e.numero;
  vendeur = e.vendeur;
  client = e.client;
  voiture = e.voiture;
}
// Destructeur
Contrat::~Contrat()
{
	#ifdef DEBUG
	cout << "Destructeur de Contrat" << endl;
	#endif
}

// setx et getX

int Contrat::getNumero() const {return numero;}
string Contrat::getVendeur() const {return vendeur;}
string Contrat::getClient() const {return client;}
string Contrat::getVoiture() const {return voiture;}

void Contrat::setNumero(int i) { numero = i;}
void Contrat::setVendeur(string s) { vendeur = s;}
void Contrat::setClient(string s) { client = s;}
void Contrat::setVoiture(string s) { voiture = s;}


// surcharge des op

ostream& operator<<(ostream& s,const Contrat& o)
{
  s << "numero : " << o.numero << ", vendeur : " << o.vendeur << ", client : " << o.client << ", voiture : " << o.voiture << endl;
  
  return s;
}


// FOnction

string Contrat::Tuple() const
{
  string r;
  r = to_string(getNumero()) + ";" + getVendeur() + ";" + getClient()+ ";" + getVoiture();
  return r;
}

void Contrat::Save(ofstream & fichier)
{
  #ifdef DEBUG
  cout << "Contrat : Save" << endl;
  #endif

  int taille = (*this).vendeur.size();
  int tailleI = (*this).client.size();
  int tailleC = (*this).voiture.size();

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }
  fichier.write((char*)&(*this).numero,sizeof(int));

  fichier.write((char*)&taille,sizeof(int)); // on enregistre le nombre de caractere de vendeur
  fichier.write((char*)(*this).vendeur.data(),taille*sizeof(char));

  fichier.write((char*)&tailleI,sizeof(int)); // on enregistre le nombre de caractere de client
  fichier.write((char*)(*this).client.data(),tailleI*sizeof(char));

  fichier.write((char*)&tailleC,sizeof(int)); // on enregistre le nombre de caractere de voiture
  fichier.write((char*)(*this).voiture.data(),tailleC*sizeof(char));



}

// permettant de charger toutes les données relatives à une voiture
// enregistrée dans le fichier dont le nom est passé en paramètre.
Contrat& Contrat::Load(ifstream & fichier)
{
  #ifdef DEBUG
  cout << "Contrat : Load" << endl;
  #endif

  int t,t2,t3;

  // if (!fichier)
  // {
  //   cout << "erreur d'ouverture ! hahha" << endl;
  //   exit(1);
  // }
  fichier.read((char*)&(*this).numero,sizeof(int)); // Lecture de numero
  
  fichier.read((char*)&t,sizeof(int)); // Lecture de vendeur
  (*this).vendeur.resize(t);
  fichier.read((char*)(*this).vendeur.data(),t*sizeof(char));
  

  fichier.read((char*)&t2,sizeof(int)); // Lecture de client
  (*this).client.resize(t2);
  fichier.read((char*)(*this).client.data(),t2*sizeof(char));

  fichier.read((char*)&t3,sizeof(int)); // Lecture de voiture
  (*this).voiture.resize(t3);
  fichier.read((char*)(*this).voiture.data(),t3*sizeof(char));

  return (*this);
}


