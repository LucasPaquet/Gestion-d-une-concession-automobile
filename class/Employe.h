#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <string>

#include "Intervenant.h"
#include "Personne.h"
#include "PasswordException.h"

using namespace std;

class Employe : public Intervenant
{
  friend ostream& operator<<(ostream& s,const Employe& c);
private:
  string login;
  string * motDePasse;
  string fonction;
public:

  static const string ADMINISTRATIF;
  static const string VENDEUR;

  //constructeur

  Employe();
  Employe(string nom, string p, int n, string l, string f);
  Employe(const Employe& p);

  //destructeur

  ~Employe();

  //setXXX et getXXX

  void setLogin(string l);
  void setMotDePasse(string m);
  void resetMotDePasse();
  void setFonction(string f);

  string getLogin()const;
  string getMotDePasse()const;
  string getFonction()const;

  // //surcharge des operateur 

  Employe& operator=(const Employe& e);

  // //Fonction
 
  string ToString() const;
  string Tuple() const;

  
};

#endif