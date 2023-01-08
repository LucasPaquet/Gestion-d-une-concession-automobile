#ifndef CONTRAT_H
#define CONTRAT_H

#include <string>
#include <fstream>


using namespace std;


class Contrat
{
  friend ostream& operator<<(ostream& s,const Contrat& o);
private:
	int numero;
	string vendeur;
	string client;
	string voiture;
public:
	
	//contruction
	Contrat();
	Contrat(int num, string ven, string c,string v);
 	Contrat(const Contrat& e);

	//destructeur
	
	~Contrat();	

	//setX et getX
	int getNumero() const;
	string getVendeur() const ;
  	string getClient() const ;
  	string getVoiture() const ;

  	void setNumero(int i);
	void setVendeur(string s);
  	void setClient(string s);
  	void setVoiture(string s);

  	// fonction

  	string Tuple() const;

  	void Save(ofstream& fichier);
  	Contrat& Load(ifstream& fichier);

};

#endif