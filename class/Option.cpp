#include <string>
#include <iostream>

#include "Option.h"


using namespace std;

//Constructeur
Option::Option()
{
  #ifdef DEBUG
  cout << "Contructeur par default de Option" << endl;
  #endif
  code = "MDR0";
  intitule = "Vitre en rouge";
  prix = 500.0;
}


Option::Option(string c,string i, float p)

{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation de Option" << endl;
  #endif
  if (c.size() ==  4)
  {
    code = c;
  }
  else
  {
    throw(OptionException("Code incorrect"));
  }
  if (i.size() !=  0)
  {
    intitule = i;
  }
  else
  {
    throw(OptionException("Intitule incorrect"));
  }
  if (p > 0)
  {
    prix = p;
  }
  else
  {
    throw(OptionException("Prix incorrect (il doit etre positif"));
  }
}

Option::Option(const Option& o)
{
  #ifdef DEBUG
  cout << "Contructeur de copie de Option" << endl;
  #endif
  code = o.code;
  intitule = o.intitule;
  prix = o.prix;
  
}
// Destructeur
Option::~Option()
{
	#ifdef DEBUG
	cout << "Destructeur de Option" << endl;
	#endif

}
//getteur
string Option::getCode() const {return code;}
string Option::getIntitule() const {return intitule;}
float Option::getPrix() const{return prix;}

// setteur
void Option::setCode(string s)
{
  if (s.size() ==  4)
  {
    code = s;
  }
  else
  {
    throw OptionException("Code incorrect");
  }
}
void Option::setIntitule(string s) 
{
  if (s.size() != 0)
  {
    intitule = s;
  }
  else
  {
    throw(OptionException("Intitule incorrect"));
  }
}
void Option::setPrix(float p) 
{
  if (p >= 0)
  {
    prix = p;
  }
  else
  {
    throw(OptionException("Prix incorrect (il doit etre positif"));
  }
 
}

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
  if (o.code.size() != 4)
  {
    throw OptionException("Code incorrect");
  }

  cout << "Intitule : ";
  getline(s,o.intitule);
  if (o.intitule.size() == 0)
  {
    throw(OptionException("Intitule incorrect"));
  }
    
  cout << "prix : ";
  s >> o.prix;
  if (o.prix < 0)
  {
    throw(OptionException("Prix incorrect (il doit etre positif"));
  }
  
  return s;
}

Option Option::operator--() // pré-incrémentation
{
  if(this->prix > 50)
  {
    (*this) = (*this) - 50.0;
  }
  else
  {
    throw(OptionException("Le prix est en dessous de 50 euros"));
  }
  
  return (*this);
}

Option Option::operator--(int)
{
  Option temp(*this);
  if(this->prix > 50)
  {
    (*this) = (*this) - 50.0;
  }
  else
  {
    throw(OptionException("Le prix est en dessous de 50 euros"));
  }
 return temp;
}






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