#include <string>
#include <iostream>

#include "Voiture.h"
#include "Modele.h"



//Constructeur
Voiture::Voiture()
{
  int i;
  #ifdef DEBUG
  cout << "Contructeur par default" << endl;
  #endif
  for(i=0;i<5;i++)
  {
    options[i] = NULL;
  }
  nom = "Voiture sans nom";
  
}

Voiture::Voiture(string n,const Modele& m)
{
  int i;
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif
  for(i=0;i<5;i++)
  {
    options[i] = NULL;
  }
  nom = n;
  setModele(m);
}
Voiture::Voiture(const Voiture& p)
{
  int i;
  Option* optionp=NULL,* optionso=NULL;

  #ifdef DEBUG
  cout << "Contructeur de copie" << endl;
  #endif

  for(i=0;i<5;i++)
  {
    optionp = p.getOption(i);
    if (optionp != NULL)
    {
      optionso = new Option(*optionp);
      setOption(optionso, i);
    }
    else
    {
      options[i] =NULL;
    }
  }
  nom = p.nom;
  setModele(p.modele);
  
}
//Destucteur
Voiture::~Voiture()
{
  int i;
	#ifdef DEBUG
	cout << "Destructeur" << endl;
	#endif
  for(i=0;i<5;i++)
  {
    if(options[i] != NULL)
    {
      delete options[i];
    }
  }

}
//getX et SetX
string Voiture::getNom() const {return nom;}
Modele Voiture::getModele() const {return modele;}
Option * Voiture::getOption(int i) const {return options[i];}

void Voiture::setNom(string s) {nom = s;}
void Voiture::setModele(const Modele& m) 
{
  modele.setNom(m.getNom());
  modele.setPuissance(m.getPuissance());
  modele.setMoteur(m.getMoteur());
  modele.setPrixDeBase(m.getPrixDeBase());
} 

void Voiture::setOption( Option* o, int i)
{
  options[i] = o;
}

//operateur de surchage

Voiture& Voiture::operator=(const Voiture& v)
{
  int i;
  Option* optionp=NULL,* optionso=NULL;

  #ifdef DEBUG
  cout << "Operateur de surcharges = " << endl;
  #endif

  for(i=0;i<5;i++)
  {
    optionp = v.getOption(i);
    if (optionp != NULL)
    {
      optionso = new Option(*optionp);
      setOption(optionso, i);
    }
    else
    {
      options[i] =NULL;
    }
  }
  nom = v.nom;
  setModele(v.modele);

  return (*this); 
}

Voiture Voiture::operator+(const Option & option)
{
  #ifdef DEBUG
  cout << "Operateur de surcharges +" << endl;
  #endif
  Voiture v(*this);
  //cout << "Operateur de surcharges +" << endl;
  v.AjouteOption(option);  
  //v.Affiche();
  return (v);
}

Voiture operator+(Option optionv,Voiture v) // pour v2 = op2 + v2;
{
  #ifdef DEBUG
  cout << "Operateur de surcharges +" << endl;
  #endif
  return (v + optionv);
}

Voiture Voiture::operator-(const Option & option)
{
  string code;
  Voiture v(*this);
  #ifdef DEBUG
  cout << "Operateur de surcharges - (const Option & option)" << endl;
  #endif
  code = option.getCode();
  v.RetireOption(code);
  return (v);
}

Voiture Voiture::operator-(string code)
{
  #ifdef DEBUG
  cout << "Operateur de surcharges - (string code)" << endl;
  #endif
  Voiture v(*this);
  v.RetireOption(code);
  return (v);
}

int Voiture::operator<(Voiture& v)
{
  float prix1,prix2;
  prix1 = getPrix();
  prix2 = v.getPrix();
  if (prix1 < prix2)
  {
    return 1;
  }
  return 0;
}

int Voiture::operator>(Voiture& v)
{
  float prix1,prix2;
  prix1 = getPrix();
  prix2 = v.getPrix();
  if (prix1 > prix2)
  {
    return 1;
  }
  return 0;
}

int Voiture::operator==(Voiture& v)
{
  float prix1,prix2;
  prix1 = getPrix();
  prix2 = v.getPrix();
  if (prix1 == prix2)
  {
    return 1;
  }
  return 0;
}

ostream& operator<<(ostream& s,Voiture& v)
{
  int i;
  s << "Nom de la voiture voiture : " << v.nom << " Modele de la voiture : " << endl;
  v.modele.Affiche();
  for (i=0;i<5;i++)
  {
    if (v.options[i] != NULL)
    {
      s << "Option n" << i << " : ";
      s << *v.options[i];
    }
  }
  
  return s;
}

Option* Voiture::operator[](int i)
{
  return getOption(i);
}



//Fonctions
void Voiture::Affiche() // affiche le Voiture au terminal
{
  int i;
	cout << "Nom de la voiture voiture : " << nom << " Modele de la voiture : " << endl;
  modele.Affiche();
  for (i=0;i<5;i++)
  {
    if (options[i] != NULL)
    {
      cout << "Option n" << i << " : ";
      options[i]->Affiche();
    }
  }
  
}

void Voiture::AjouteOption(const Option & option) // ajoute une option a la voiture
{
  int i;
  Option * optionp = NULL;
  for (i=0;i<5;i++)
  {
    optionp = getOption(i);
    if (optionp == NULL)
    {
      optionp = new Option;
      optionp->setCode(option.getCode());
      optionp->setIntitule(option.getIntitule());
      optionp->setPrix(option.getPrix());
      break;
    }
  }
  setOption(optionp, i);
}

void Voiture::RetireOption(string code) // retire une option a la voiture
{
  int i;
  
  for (i=0;i<5;i++)
  {
    if(options[i] != NULL)
    {
      if (options[i]->getCode() == code)
      {

        delete options[i];
        options[i] = NULL;
        break;
      }
    }
  }
}

float Voiture::getPrix()
{
  float prixTotal=0;
  int i;

  prixTotal = prixTotal + modele.getPrixDeBase();

  for (i=0;i<5;i++)
  {
    if (options[i] != NULL)
    {
      prixTotal = prixTotal + options[i]->getPrix();
    }
  }
  return prixTotal;
}