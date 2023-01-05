
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

// void importeModeles(string nomFichier) : qui importe les modèles présents dans le
// fichier csv dont le nom est passé en paramètre. Les modèles lus seront placés dans le
// conteneur de modèles de la classe Garage
void Garage::importeModeles(string nomFichier)
{
    FILE * fp;
    Modele mod;
    char * buf = NULL;
    int i;
    size_t len = 0;
    ssize_t read; // vérifier que on est pas a la fin du fichier
    const char * separateur = ";"; // tout les caractère pour séparé la ligne
    char * champs;
    Moteur m;
    char fichier[100] = "FichiersCSV/";

    strcat(fichier,nomFichier.c_str()); // pour concatener pour avoir le chemin vers le csv

    fp = fopen(fichier, "r");
    if (fp == NULL)
    {
        cout << "Erreur d'ouverture !" << endl;
        exit(0);
    }

    getline(&buf, &len, fp); // pour sauter la première ligne qui sont les intitulé des colonnes

    while ((read = getline(&buf, &len, fp)) != -1) // lecture ligne par ligne du fichier jusqu'a qu'il n'y  a plus de d'options
    {
        i=0;

        champs = strtok ( buf, separateur ); // lecture le champs
        while ( champs != NULL ) // jusqu'a un retour a la ligne
        {
          cout << &champs << endl;
            switch(i) // pour remplir le bon champs du modele
            {
              case 0: mod.setNom(champs);
                      break;
              case 1: mod.setPuissance(atoi(champs));
                      break;
              case 2: mod.setMoteur(Diesel);
                      break;
              case 3: mod.setImage(champs);
                      break;
              case 4: mod.setPrixDeBase(atof(champs));
                      break;
            }
            
            i++;
            champs = strtok ( NULL, separateur ); // chercher le prochain champs
        }
        ajouteModele(mod);


    }

    for (int i = 0; i < 15; ++i)
    {
      cout << getModele(i) << endl;
    }
}

int Garage::getSizeModele() // retourne la taille du vecteur
{
  return modeles.size();
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

// qui importe les options présentes dans le
// fichier csv dont le nom est passé en paramètre. Les options lues seront placées dans le
// conteneur d’options de la classe Garage.
void Garage::importeOptions(string nomFichier)
{
    FILE * fp;
    Option opt;
    char * buf = NULL;
    int i;
    size_t len = 0;
    ssize_t read; // vérifier que on est pas a la fin du fichier
    const char * separateur = ";"; // tout les caractère pour séparé la ligne
    char * champs;
    char fichier[100] = "FichiersCSV/";

    strcat(fichier,nomFichier.c_str()); // pour concatener pour avoir le chemin vers le csv

    fp = fopen(fichier, "r");
    if (fp == NULL)
    {
        cout << "Erreur d'ouverture !" << endl;
        exit(0);
    }

    getline(&buf, &len, fp); // pour sauter la première ligne qui sont les intitulé des colonnes

    while ((read = getline(&buf, &len, fp)) != -1) // lecture ligne par ligne du fichier jusqu'a qu'il n'y  a plus de d'options
    {

        i=0;
        champs = strtok ( buf, separateur ); // lecture le champs
        while ( champs != NULL ) // jusqu'a un retour a la ligne
        {
            switch(i) // pour remplir le bon champs de l'opt
            {
              case 0: 
                      opt.setCode(champs);
                      break;
              case 1: opt.setIntitule(champs);
                      break;
              case 2: opt.setPrix(atof(champs));
                      break;
            }
            
            i++;
            champs = strtok ( NULL, separateur ); // chercher le prochain champs
        }
        ajouteOption(opt);

    }
}

int Garage::getSizeOption() // retourne la taille du vecteur
{
  return options.size();
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
