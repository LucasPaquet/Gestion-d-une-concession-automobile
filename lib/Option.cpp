#include <string>
#include <iostream>

#include "Option.h"


using namespace std;

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

Option::Option(std::string c,std::string i, float p)
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
std::string Option::getCode() const {return code;}
std::string Option::getIntitule() const {return intitule;}
float Option::getPrix() const{return prix;}

// setteur
void Option::setCode(std::string s) {code = s;}
void Option::setIntitule(std::string s) {intitule = s;}
void Option::setPrix(float p) {prix = p;}

//Fonctions
void Option::Affiche() // affiche l'Option au terminal
{

	cout << "Code : " << code << ", Intitule : " << intitule << ", prix : " << prix << endl;
  
}