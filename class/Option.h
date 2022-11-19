#ifndef OPTION_H
#define OPTION_H

#include "OptionException.h"
#include <string>

using namespace std;

class ErrCalcul {};

class Option
{
  friend ostream& operator<<(ostream& s,const Option& o);
  friend istream& operator>>(istream& s, Option& o);
private:
  string code;
  string intitule;
  float prix;

public:
  //constructeur
  Option();
  Option(string code, string intitule, float prix);
  Option(const Option& p);
  //destructeur
  ~Option();
  // getteur
  string getCode() const ;
  string getIntitule() const ;
  float getPrix() const;
  //setteur
  void setCode(string s);
  void setIntitule(string s);
  void setPrix(float p);

  //operateur de surchages

  Option operator-(float ristourne);
  Option operator--();
  Option operator--(int);

  //fonctions

  void Affiche();
};

#endif