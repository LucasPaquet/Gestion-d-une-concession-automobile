#include <string>
#include <iostream>

#include "Personne.h"
#include "Employe.h"

#include "PasswordException.h"

//Constructeur
Employe::Employe() : Intervenant()
{
  #ifdef DEBUG
  cout << "Contructeur par default de employe" << endl;
  #endif
  login = "paquet";
  motDePasse = NULL;
  fonction = "VENDEUR";

}

Employe::Employe(string nom, string p, int n, string l, string f) : Intervenant(nom,p,n)
{
  #ifdef DEBUG

  cout << "Contructeur initialisation de employe" << endl;

  #endif
  setLogin(l);
  motDePasse =NULL;
  setFonction(f);
}

Employe::Employe(const Employe& e)
{
  #ifdef DEBUG
  cout << "Contructeur de copie de employe" << endl;
  #endif
  login = e.login;
  motDePasse = NULL;
  if(e.motDePasse !=NULL)
        setMotDePasse(e.getMotDePasse());
    else
        resetMotDePasse();
  fonction = e.fonction;
  numero = e.numero;
  nom = e.nom;
  prenom = e.prenom;
  
}

//Destructeur 

Employe::~Employe()
{
  #ifdef DEBUG
  cout << "Destructeur de Employe" << endl;
  #endif
  cout << "Destructeur de Employe" << endl;
}

//setXXX et getXXX

void Employe::setLogin(string l) {login = l;}

void Employe::setMotDePasse(string m) 
{
  if (m.empty() == 0)
  {
    if (m.size() < 6)
    {
      throw(PasswordException("INVALID_LENGTH",1));
    }
    else
    {
      if (m.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 0) == m.npos)
      {
        throw(PasswordException("ALPHA_MISSING", 2));
      }
      else
      {
        if (m.find_first_of("0123456789", 0) == m.npos)
        {
          throw(PasswordException("DIGIT_MISSING", 3));
        }
        else
        {
          if(motDePasse)
          {
            delete motDePasse;
          }
          
          motDePasse = new string;
          *motDePasse = m;
        }
      }
    }
    
  }
}

void Employe::resetMotDePasse() 
{
  if(motDePasse !=NULL)
  {
    delete motDePasse;
    motDePasse = NULL;
  }

}

void Employe::setFonction(string f) {fonction = f;}

string Employe::getLogin() const {return login;}

string Employe::getMotDePasse() const
{
  if (motDePasse != NULL)
  {
    return *motDePasse;
  }
  else
  {
    throw(PasswordException("NO_PASSWORD", 4));
  }
  return "";
} 

string Employe::getFonction() const {return fonction;}

// operateur de surchages

Employe& Employe::operator=(const Employe& e)
{
  #ifdef DEBUG
  cout << "operator= de Employe" << endl;
  #endif
  login = e.login;
  fonction = e.fonction;
  numero = e.numero;
  nom = e.nom;
  prenom = e.prenom;

  setLogin(e.getLogin());
  if(e.motDePasse !=NULL)
        setMotDePasse(e.getMotDePasse());
    else
        resetMotDePasse();
  setFonction(e.getFonction());

  return *this;
}

ostream& operator<<(ostream& s,const Employe& e)
{
  s << endl << "Nom    : " << e.getNom() << endl;
  s << "Prenom : " << e.getPrenom() << endl;
  s << "Numero : " << e.getNumero() << endl;
  s << endl << "Login    : " << e.login << endl;
  if (e.motDePasse)
  {
    s << "Mot de passe : " << *e.motDePasse << endl;
  }
  else
  {
    s << "Mot de passe : /" << endl;
  }
  s << "Fonction : " << e.fonction << endl;
  return s;
}

// // Fonction 


string Employe::ToString() const
{
  string r;
  if (getFonction() == "Vendeur")
  {
    r = "[V" + to_string(getNumero()) + "] " + getNom() + " " + getPrenom();
  }
  else
  {
    r = "[A" + to_string(getNumero()) + "] " + getNom() + " " + getPrenom();
  }
  return r;
}

string Employe::Tuple() const
{
  string r;
  r = to_string(getNumero()) + ";" + getNom() + ";" + getPrenom()+ ";" + getFonction();
  return r;
}

