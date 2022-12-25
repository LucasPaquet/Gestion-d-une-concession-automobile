
#include "Garage.h"

static int numCourant = 1;

//Constructeur
Garage::Garage()
{
  #ifdef DEBUG
  cout << "Contructeur par default de Garage" << endl;
  #endif
}

//Destructeur

Garage::~Garage()
{
  #ifdef DEBUG
  cout << "Destructeur de Garage" << endl;
  #endif
}

// fonctions modele

void Garage::ajouteModele(const Modele & m)
{
  modeles.insere(m);
}

void Garage::afficheModelesDisponibles()
{
    modeles.Affiche();
}

Modele Garage::getModele(int indice)
{
  return modeles[indice];
}


// Option

void Garage::ajouteOption(const Option & o)
{
  options.insere(o);
}

void Garage::afficheOptionsDisponibles()
{
  options.Affiche();
}

Option Garage::getOption(int indice)
{
  return options[indice];
}

// Fonction Client

void Garage::ajouteClient(string nom,string prenom,string gsm)
{
  // Client tmp(nom,prenom,clients.size(),gsm);
  Client tmp(nom,prenom,numCourant,gsm);
  numCourant++;
  clients.insere(tmp);
}
void Garage::afficheClients() 
{
  clients.Affiche();
}
void Garage::supprimeClientParIndice(int ind)
{
  clients.retire(ind);
}
void Garage::supprimeClientParNumero(int num)
{
  for(int i=0;i<clients.size();i++)
  {
    if (clients[i].getNumero() == num)
    {
      clients.retire(i);
    }
  } 
}

// Fonction employe

void Garage::ajouteEmploye(string nom,string prenom,string login,string fonction)
{
  Employe tmp;
  tmp.setNom(nom);
  tmp.setPrenom(prenom);
  tmp.setNumero(numCourant);
  tmp.setLogin(login);
  tmp.setFonction(fonction);
  numCourant++;
  employes.insere(tmp);
}

void Garage::afficheEmployes()
{
  employes.Affiche();
} 

void Garage::supprimeEmployeParIndice(int ind)
{
  employes.retire(ind);
}

void Garage::supprimeEmployeParNumero(int num)
{
  for(int i=0;i<employes.size();i++)
  {
    if (employes[i].getNumero() == num)
    {
      employes.retire(i);
    }
  }
}

Garage& Garage::getInstance()
{
  return instance;
}
Garage Garage::instance = Garage();

Voiture& Garage::getProjetEnCours()
{
  return projetEnCours;
}
Voiture Garage::projetEnCours = Voiture();

void Garage::resetProjetEnCours()
{
  projetEnCours = Voiture();
}
