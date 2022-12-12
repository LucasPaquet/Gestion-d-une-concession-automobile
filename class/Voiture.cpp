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
  if (options[i] == NULL)
  {
    options[i] = o;
  }
  else
  {
    throw(OptionException("Option deja presente"));
  }
  
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
  int i, v; // v pour verifier les codes après avoir trouver une place libre
  Option * optionp = NULL, * optionv = NULL; // optionv pour garder le pointeur de la place libre avant de continer a chercher avec optionp
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
    else
    {
      if (optionp->getCode() == option.getCode()) // a chaque fois que la place est prise (optionp != NULL), on verifie que le code est différent que celui qu'on rajoute sinon on lance une exception 
      {
        throw(OptionException("La voiture contient une option avec le meme code"));
        break;
      }
    }
  }

  v = i; // on garde la position de i parce que on va continuer a verifier si les autres codes sont différent de celui que l'on veut rajouter
  optionv = optionp; 
  for (i=i+1;i<5;i++) // i = i + 1 par ce que on ne va pas vérifier un code alors que le pointeur est forcément NULL
  {
    optionp = getOption(i);
    if (optionp != NULL)
    {
      if (optionp->getCode() == option.getCode())
      {
        v = 5; // v = 5 pour mettre false a la condition en bas et etre sur que il n'ajoute pas l'option
        throw(OptionException("La voiture contient deja 5 option"));
        break;
      }
    }
  }
  if (v!=5) // pour verifier si la voiture n'est pas remplie d'option
  {
    setOption(optionv, v);
  }
  else
  {
    throw(OptionException("La voiture contient deja 5 option"));
  }
  
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

  if (i==5)
  {
    throw(OptionException("L'option que vous essayer de suprrimez n'est pas équipé sur la voiture"));
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