#ifndef GARAGE_H
#define GARAGE_H

#include <string>
#include <iostream>

#include "Employe.h"
#include "Modele.h"
#include "Option.h"
#include "Client.h"
#include "Vecteur.h"
#include "Voiture.h"

using namespace std;

class Garage
{

private:
	Vecteur<Client> clients; // ou Vecteur<Client>
	Vecteur<Employe> employes; // ou Vecteur<Employe>
	Vecteur<Modele> modeles;
	Vecteur<Option> options;

	static Garage instance; // singleton de l'application

	//Constructeur

	Garage();

	//Destructeur

	~Garage();

	// surcharge operateur

	Garage& operator=(const Garage& g);

	static Voiture projetEnCours;

public:
	
	static Garage& getInstance();
	static Voiture& getProjetEnCours();

	static void resetProjetEnCours();

	//modele

	void ajouteModele(const Modele & m);
	void afficheModelesDisponibles();
	Modele getModele(int indice);

	// Option

	void ajouteOption(const Option & o);
	void afficheOptionsDisponibles();
	Option getOption(int indice);

	//Client

	void ajouteClient(string nom,string prenom,string gsm);
	void afficheClients();
	void supprimeClientParIndice(int ind);
	void supprimeClientParNumero(int num);

	//Employe

	void ajouteEmploye(string nom,string prenom,string login,string fonction);
	void afficheEmployes();
	void supprimeEmployeParIndice(int ind);
	void supprimeEmployeParNumero(int num);
};


#endif