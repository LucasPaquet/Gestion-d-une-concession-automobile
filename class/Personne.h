#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>
using namespace std;
class Personne
{
	friend ostream& operator<<(ostream& s,const Personne& p);
	friend istream& operator>>(istream& s, Personne& o);
protected:
	string nom;
	string prenom;
private:
	
public:
	//constructeur
	Personne();
	Personne(string nom, string prenom);
	Personne(const Personne& p);

	//destructeur

	~Personne();

	//getXXX et setXXX
	string getNom() const ;
  	string getPrenom() const ;
  	void setNom(string s);
  	void setPrenom(string s);

  	//surcharge des operateur 

  	Personne& operator=(const Personne& v);

  	//fonctions 


};

// ---------- INTERVENANT ------------------

class Intervenant : public Personne
{
protected:
	int numero;
public:
	Intervenant();
	Intervenant(string nom, string prenom, int n);
	~Intervenant();

	// getXXX et setXXX

	int getNumero() const ;
  	void setNumero(int n);

	//surcharge des operateur 

  	Intervenant& operator=(const Intervenant& i);
	
	//Fonctions

	virtual string ToString() const = 0;
	virtual string Tuple() const = 0;
};


#endif