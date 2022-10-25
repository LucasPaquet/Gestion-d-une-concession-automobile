#include <string>
#include <iostream>

#include "Option.h"

//Constructeur
Option::Option()
{
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
  #endif
  code = "MDR0";
  intitule = "Vitre en rouge";
  prix = 500.0;
}

Option::Option(string c,string i, float p)
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif
  code= c;
  intitule =i;
  prix = p;
}

Option::Option(const Option& o)
{
  #ifdef DEBUG
  cout << "Contructeur de copie" << endl;
  #endif
  code = o.code;
  intitule = o.intitule;
  prix = o.prix;
  
}
// Destructeur
Option::~Option()
{
	#ifdef DEBUG
	cout << "Destructeur" << endl;
	#endif
}
//getteur
string Option::getCode() const {return code;}
string Option::getIntitule() const {return intitule;}
float Option::getPrix() const{return prix;}

// setteur
void Option::setCode(string s) {code = s;}
void Option::setIntitule(string s) {intitule = s;}
void Option::setPrix(float p) {prix = p;}

// surcharges operateur

Option Option::operator-(float ristourne)
{
  #ifdef DEBUG
  cout << "Operateur de surcharges - (string code)" << endl;
  #endif
  Option v(*this);
  v.prix = v.prix - ristourne;
  return (v);
}

ostream& operator<<(ostream& s,const Option& o)
{
  s << "Code : " << o.code << ", Intitule : " << o.intitule << ", prix : " << o.prix << endl;
  
  return s;
}

istream& operator>>(istream& s, Option& o)
{
  cout << "Code : ";
  getline(s,o.code);
  cout << "Intitule : ";
  getline(s,o.intitule);
  cout << "prix : ";
  s >> o.prix;
  return s;
}

Option Option::operator--() // pré-incrémentation
{
  (*this) = (*this) - 50.0;
  return (*this);
}

Option Option::operator--(int)
{
 Option temp(*this);
 (*this) = (*this) - 50.0;
 return temp;
}




//Fonctions
void Option::Affiche() // affiche l'Option au terminal
{

	cout << "Code : " << code << ", Intitule : " << intitule << ", prix : " << prix << endl;
  
}