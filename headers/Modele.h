#ifndef MODELE_H
#define MODELE_H

enum Moteur{Essence, Diesel, Electrique, Hybride};

class Modele
{
private:
  char * nom;
  int puissance;

  Moteur moteur;
  float prixDeBase;
public:
  //constructeur
  Modele();
  Modele(char * c, int i, Moteur m,float f);
  Modele(const Modele& p);
  //destructeur
  ~Modele();
  // getteur
  char * getNom();
  int getPuissance();
  Moteur getMoteur();
  float getPrixDeBase();
  //setteur
  void setNom(char * );
  void setPuissance(int );
  void setMoteur(Moteur );
  void setPrixDeBase(float ); 
  //fonctions
  void Affiche();
};

#endif