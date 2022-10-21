#ifndef OPTION_H
#define OPTION_H
#include <string>
using namespace std;
class Option
{
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
  //fonctions
  void Affiche();
};

#endif