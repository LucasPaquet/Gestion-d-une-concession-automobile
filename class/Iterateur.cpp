#include <string>
#include <iostream>

#include "Iterateur.h"

template <class T>
Iterateur<T>::Iterateur(Vecteur<T>& source) : p(source),pData(source.v)
{
	#ifdef DEBUG
	cout << "Contructeur par initialisation de Iterateur" << endl;
	#endif
}

template <class T>
Iterateur<T>::~Iterateur()
{
	#ifdef DEBUG
	cout << "Destructeur de Iterateur" << endl;
	#endif
}

// opetateur de surcharge

template <class T>
bool Iterateur<T>::operator++() // pré-incrémentation
{
	if(!end())
	{
		pData++;
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Iterateur <T>::operator++(int)
{
	return operator++();
}

template <class T> 
Iterateur<T>::operator T()
{
	return *pData;
}



// Fonctions 
template <class T>
bool Iterateur<T>::end() const //end() qui retourne le booléen true si l’itérateur est situé au bout du vecteur.
{
	if(pData - p.v >= p.size())
		return true;
	else
		return false;
}
template <class T>
void Iterateur<T>::reset() // reset() qui réinitialise l’itérateur au début du vecteur.
{
	pData = p.v;
}

// Instanciation des templates

template class Iterateur<int>;
template class Iterateur<Client>;