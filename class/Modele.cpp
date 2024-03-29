#include <iostream>
#include <string.h>

#include "Modele.h"

using namespace std;



//Constructeur

Modele::Modele()
{
  #ifdef DEBUG
  cout << "Contructeur par default de modele" << endl;
  #endif
  nom =NULL;
  setNom("Voiture sans nom");
  puissance = 100;
  moteur = Electrique;
  prixDeBase = 12500.0;
  image = "208.jpg";
}
Modele::Modele(const char * c, int i, Moteur m,float f, string s)
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif
  nom=NULL;
  setNom(c);
  puissance = i;
  moteur = m;
  prixDeBase = f;
  image = s;
}
Modele::Modele(const Modele& p)
{
  #ifdef DEBUG
  cout << "Contructeur de copie" << endl;
  #endif
  nom =NULL;
  setNom(p.getNom());
  puissance = p.puissance;
  moteur = p.moteur;
  prixDeBase = p.prixDeBase;
  image = p.image;
}

//Destucteur

Modele::~Modele()
{
  #ifdef DEBUG
  cout << "Destructeur de modele" << endl;
  //this->Affiche();
  #endif
  if (nom)
    delete [] nom;
}

//getX et SetX

const char * Modele::getNom() const {return nom;}
int Modele::getPuissance() const {return puissance;}
Moteur Modele::getMoteur() const {return moteur;}
float Modele::getPrixDeBase() const {return prixDeBase;}
string Modele::getImage() const {return image;}

void Modele::setNom(const char * c) 
{
  if (c)
  {
    if (nom)
    {
      delete [] nom;  
    }
    
    nom = new char[strlen(c)+1];
    strcpy(nom, c);
  }
}
void Modele::setPuissance(int p) 
{
  if (p>=0)
    puissance = p;
}
void Modele::setMoteur(Moteur m) {moteur = m;}
void Modele::setPrixDeBase(float p) 
{
  if (prixDeBase >= 0)
    prixDeBase = p;
}
void Modele::setImage(string s) {image = s;}

// operateur de surchages

ostream& operator<<(ostream& s,const Modele& m)
{
  s << "Nom : "<< m.nom << ", puissance : " << m.puissance << ", Prix de base : " << m.prixDeBase << ", Image : " << m.image <<", Moteur : ";
  switch(m.moteur)
  {
    case Essence: s << "Essence" << endl;
      break;
    case Electrique: s << "Electrique" << endl;
      break;
    case Diesel: s << "Diesel" << endl;
      break;
    case Hybride: s << "Hybride" << endl;
      break;
  }
  
  return s;
}

istream& operator>> (istream& s, Modele& m)
{
  string buff;
  int moteurInt;
  cout << "Nom : ";
  getline(cin,buff);
  cout << "Puissance : ";
  s >> m.puissance;
  cout << "Prix de base : ";
  s >> m.prixDeBase;
  cout << "Moteur : ";
  s >> moteurInt;
  m.moteur = (Moteur)moteurInt;
  
  m.setNom(buff.data());
  return s;
}
 Modele& Modele::operator=(const Modele& modele)
 {

    setNom(modele.getNom());
    setPuissance(modele.getPuissance());
    setPrixDeBase(modele.getPrixDeBase());
    setMoteur(modele.getMoteur());

    setImage(modele.getImage());

    return (*this);
  
 }
//Fonctions

void Modele::Affiche() // affiche le modele au terminal
{
  cout << "Nom : "<< nom << ", puissance : " << puissance << ", Prix de base : " << prixDeBase <<", Image : " << image << ", Moteur : ";
  switch(moteur)
  {
    case Essence: cout << "Essence" << endl;
      break;
    case Electrique: cout << "Electrique" << endl;
      break;
    case Diesel: cout << "Diesel" << endl;
      break;
    case Hybride: cout << "Hybride" << endl;
      break;
  }
}



void Modele::Save(ofstream & fichier)
{
  #ifdef DEBUG
  cout << "Modele : Save" << endl;
  #endif
  int taille = strlen((*this).nom), tailleI = (*this).image.size();
  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }
  fichier.write((char*)&taille,sizeof(int)); // nom
  fichier.write((char*)(*this).nom,taille*sizeof(char));


  fichier.write((char*)&(*this).puissance,sizeof(int)); // puissance

  fichier.write((char*)&(*this).moteur,sizeof(Moteur)); // moteur

  fichier.write((char*)&(*this).prixDeBase,sizeof(float)); // prixDeBase

  fichier.write((char*)&tailleI,sizeof(int)); // on enregistre le nombre de caractere de image
  fichier.write((char*)(*this).image.data(),tailleI*sizeof(char));

}


void Modele::Load(ifstream & fichier)
{
  #ifdef DEBUG
  cout << "Modele : Load" << endl;
  #endif
  int t, t2;
  if (!fichier)
  {
    cout << "erreur d'ouverture !" << endl;
    exit(1);
  }

  fichier.read((char*)&t,sizeof(int)); // nom
  delete[] (*this).nom;
  (*this).nom = new char[t+1];
  fichier.read((char*)(*this).nom,t*sizeof(char));

  fichier.read((char*)&(*this).puissance,sizeof(int)); // puissance

  fichier.read((char*)&(*this).moteur,sizeof(Moteur)); // moteur

  fichier.read((char*)&(*this).prixDeBase,sizeof(float)); // prix de base

  fichier.read((char*)&t2,sizeof(int)); // Lecture de image
  (*this).image.resize(t2);
  fichier.read((char*)(*this).image.data(),t2*sizeof(char));

}