#ifndef INTERVENANT_H
#define INTERVENANT_H

#include <string>
#include "Personne.h"

using namespace std;

class Intervenant : public Personne
{
protected:
	int numero;
public:
	Intervenant();
	Intervenant(string nom, string prenom, int n);
	Intervenant(const Intervenant& i);
	//faire constructeur de copie et separer les classes dans deux fichiers
	virtual ~Intervenant();

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