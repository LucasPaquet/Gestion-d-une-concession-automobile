#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Personne.h"

using namespace std;

class Client : public Intervenant
{
  friend ostream& operator<<(ostream& s,const Client& c);
private:
  string gsm;
public:

  //constructeur

  Client();
  Client(string nom, string p, int n, string g);
  Client(const Client& p);

  //destructeur

  ~Client();

  //setXXX et getXXX

  void setGsm(string n) ;
  string getGsm()const;

  //surcharge des operateur 

  Client& operator=(const Client& c);

  //Fonction
  string ToString() const;
  string Tuple() const;
  
};

#endif