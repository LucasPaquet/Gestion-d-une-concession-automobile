#ifndef GARAGE_H
#define GARAGE_H

#include <string.h>
#include <iostream>

#include "Employe.h"
#include "Modele.h"
#include "Option.h"
#include "Client.h"
#include "Vecteur.h"
#include "Voiture.h"
#include "Modele.h"
#include "Contrat.h"


#include <string>

using namespace std;

class Garage
{

private:
	Vecteur<Client> clients; // ou Vecteur<Client>
	Vecteur<Employe> employes; // ou Vecteur<Employe>
	Vecteur<Modele> modeles;
	Vecteur<Option> options;
	Vecteur<Contrat> contrats;

	static Garage instance; // singleton de l'application

	//Constructeur

	Garage();

	//Destructeur

	~Garage();

	// surcharge operateur

	Garage& operator=(const Garage& g);

	static Voiture projetEnCours;

public:
	
	Employe* employe;
	static Garage& getInstance();
	static Voiture& getProjetEnCours();

	static void resetProjetEnCours();

	//modele

	void ajouteModele(const Modele & m);
	void afficheModelesDisponibles();
	Modele getModele(int indice);
	void importeModeles(string nomFichier);
	int getSizeModele();

	// Option

	void ajouteOption(const Option & o);
	void afficheOptionsDisponibles();
	Option getOption(int indice);
	void importeOptions(string nomFichier);
	int getSizeOption();

	//Client

	void ajouteClient(string nom,string prenom,string gsm);
	void afficheClients();
	void supprimeClientParIndice(int ind);
	void supprimeClientParNumero(int num);
	Client getClient(int indice);
	int getSizeClient();

	//Employe

	void ajouteEmploye(string nom,string prenom,string login,string fonction);
	void afficheEmployes();
	void supprimeEmployeParIndice(int ind);
	void supprimeEmployeParNumero(int num);
	Employe getEmploye(int indice);
	Employe* getEmployePt(int indice);
	int getSizeEmploye();

	// Contrat

	void ajouteContrat(string c,string v);
	void supprimeContratParNumero(int num);
	Contrat getContrat(int indice);
	int getSizeContrat();

	// Fonction

	void Save(ofstream& fichier);
  	void Load(ifstream& fichier);
    
};


#endif