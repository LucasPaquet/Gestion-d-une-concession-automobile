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
  Modele(const char * c, int i, Moteur m,float f);
  Modele(const Modele& p);
  //destructeur
  ~Modele();
  // getteur
  const char * getNom() const;
  int getPuissance() const;
  Moteur getMoteur() const;
  float getPrixDeBase() const;
  //setteur
  void setNom(const char * );
  void setPuissance(int );
  void setMoteur(Moteur );
  void setPrixDeBase(float ); 
  //fonctions
  void Affiche();
};

#endif