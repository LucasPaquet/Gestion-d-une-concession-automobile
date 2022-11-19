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

};

#endif