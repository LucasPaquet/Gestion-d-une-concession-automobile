
#include "Garage.h"

static int numCourant = 1;
static int ctrCourant = 1;
static Employe * logEmp;

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
          
            switch(i) // pour remplir le bon champs du modele
            {
              case 0: mod.setNom(champs); 
                      break;
              case 1: mod.setPuissance(atoi(champs));
                      break;
              case 2: if (strcmp(champs, "hybride") == 0)
                      {
                        mod.setMoteur(Hybride);
                      }
                      else 
                      {
                        if (strcmp(champs, "diesel") == 0)
                        {
                          mod.setMoteur(Diesel);
                        }
                        else 
                        {
                          if (strcmp(champs, "electrique") == 0)
                          {
                            mod.setMoteur(Electrique);
                          }
                          else 
                          {
                            mod.setMoteur(Essence);
                          }
                        }
                      }
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

Client Garage::getClient(int indice)
{
  return clients[indice];
}

int Garage::getSizeClient(){ return clients.size(); }

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

Employe Garage::getEmploye(int indice)
{
  return employes[indice];
}
Employe* Garage::getEmployePt(int indice)
{
  return &employes[indice];
}
int Garage::getSizeEmploye(){ return employes.size(); }


// Contrat

void Garage::ajouteContrat(string c,string v)
{
  Contrat ctr;
  ctr.setNumero(ctrCourant);
  ctr.setVendeur(employe->getNom());
  ctr.setClient(c);
  ctr.setVoiture(v);
  contrats.insere(ctr);
  ctrCourant++;
}

void Garage::supprimeContratParNumero(int ind)
{
  contrats.retire(ind);
}

int Garage::getSizeContrat(){ return contrats.size(); }

Contrat Garage::getContrat(int indice)
{
  return contrats[indice];
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

// fonction

void Garage::Save(ofstream & fichier)
{
  #ifdef DEBUG
  cout << "Garage : Save" << endl;
  #endif

  int i, sizeE, sizeC, sizeCtr ;
  sizeE = employes.size();
  sizeC = clients.size();
  sizeCtr = contrats.size();

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }

  fichier.write((char*)&numCourant,sizeof(int)); // numCourant
  fichier.write((char*)&ctrCourant,sizeof(int)); // nombre courant de contrat

  fichier.write((char*)&sizeE,sizeof(int)); // nombre d'employe
  for(i=0;i<employes.size();i++)
  {
    employes[i].Save(fichier);
  }

  fichier.write((char*)&sizeC,sizeof(int)); // nombre d'employe
  for(i=0;i<clients.size();i++)
  {
    clients[i].Save(fichier);
  }

  fichier.write((char*)&sizeCtr,sizeof(int)); // nombre de contrat

  for(i=0;i<contrats.size();i++)
  {
    contrats[i].Save(fichier);
  }
}

void Garage::Load(ifstream & fichier)
{
  #ifdef DEBUG
  cout << "Garage : Load" << endl;
  #endif

  int num, sizeE, sizeC,sizeCtr, i;

  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }

  fichier.read((char*)&num,sizeof(int)); // Lecture de num courant

  numCourant = num; // on remet la variable statique a jour

  fichier.read((char*)&sizeCtr,sizeof(int)); // Lecture de la taille de contrat

  ctrCourant = sizeCtr; // on remet la variable statique a jour

  fichier.read((char*)&sizeE,sizeof(int)); // Lecture de la taille de employe

  for(i=0;i<sizeE;i++)
  {
    employes.insere(employes[i].Load(fichier));
  }

  fichier.read((char*)&sizeC,sizeof(int)); // Lecture de la taille de employe

  for(i=0;i<sizeC;i++)
  {
    clients.insere(clients[i].Load(fichier));
  }

  
  fichier.read((char*)&sizeCtr,sizeof(int)); // Lecture de la taille de employe
  for(i=0;i<sizeCtr;i++) // -1 car ctrCourant est le num de contrat d'après
  {
    contrats.insere(contrats[i].Load(fichier));
  }

}