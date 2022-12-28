#ifndef MODELE_H
#define MODELE_H

#include <fstream>

using namespace std;

enum Moteur{Essence, Diesel, Electrique, Hybride};

class Modele
{

  friend ostream& operator<<(ostream& s,const Modele& m);
  friend istream& operator>>(istream& s, Modele& m);

private:
  char * nom;
  int puissance;
  Moteur moteur;
  float prixDeBase;
  string image;
public:
  //constructeur

  Modele();
  Modele(const char * c, int i, Moteur m,float f, string s);
  Modele(const Modele& p);

  //destructeur

  ~Modele();

  // getteur

  const char * getNom() const;

  int getPuissance() const;
  Moteur getMoteur() const;
  float getPrixDeBase() const;
  string getImage() const;

  //setteur

  void setNom(const char * );
  void setPuissance(int );
  void setMoteur(Moteur );
  void setPrixDeBase(float ); 
  void setImage(string);

  //fonctions

  void Affiche();
  void Save(ofstream& fichier);
  void Load(ifstream& fichier);
};

#endif