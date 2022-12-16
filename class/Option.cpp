#include <string>
#include <iostream>

#include "Option.h"

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




//Fonctions
void Option::Affiche() // affiche l'Option au terminal
{

  cout << "Code : " << code << ", Intitule : " << intitule << ", prix : " << prix << endl;
  
}
void Option::Save(ofstream & fichier)
{
  #ifdef DEBUG
  cout << "Option : Save" << endl;
  #endif
  cout << "Option : Save" << endl;

  int taille = (*this).code.size();
  int tailleI = (*this).intitule.size();

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }

  fichier.write((char*)&taille,sizeof(int)); // on enregistre le nombre de caractere de code
  fichier.write((char*)(*this).code.data(),taille*sizeof(char));

  fichier.write((char*)&tailleI,sizeof(int)); // on enregistre le nombre de caractere de intitule
  fichier.write((char*)(*this).intitule.data(),tailleI*sizeof(char));

  fichier.write((char*)&(*this).prix,sizeof(float));
  


}

// permettant de charger toutes les données relatives à une voiture
// enregistrée dans le fichier dont le nom est passé en paramètre.
void Option::Load(ifstream & fichier)
{
  #ifdef DEBUG
  cout << "Option : Load" << endl;
  #endif
  cout << "Option : Load" << endl;
  int t;
  int t2;
  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }
  fichier.read((char*)&t,sizeof(int)); // Lecture de code
  (*this).code.resize(t);
  fichier.read((char*)(*this).code.data(),t*sizeof(char));
  

  fichier.read((char*)&t2,sizeof(int)); // Lecture de intitule
  (*this).intitule.resize(t2);
  fichier.read((char*)(*this).intitule.data(),t2*sizeof(char));

  fichier.read((char*)&(*this).prix,sizeof(float)); // Lecture de prix
}


