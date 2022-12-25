#include <string>
#include <iostream>

#include "Vecteur.h"


//Constructeur

template <class T>
Vecteur<T>::Vecteur()
{
	#ifdef DEBUG
	cout << "Contructeur par default de Vecteur" << endl;
	#endif
	v = new T[10];
	_sizeMax = 10;
	_size = 0;
}

template <class T>
Vecteur<T>::Vecteur(int i)
{
	#ifdef DEBUG
	cout << "Contructeur initialisation de Vecteur" << endl;
	#endif
	_sizeMax = i;
	v = new T[i];
	_size = 0;
}

template <class T>
Vecteur<T>::Vecteur(const Vecteur& vec)
{
	#ifdef DEBUG
	cout << "Contructeur de copie de Vecteur" << endl;
	#endif
	int i;
	_sizeMax = vec._sizeMax;
	v = new T[vec._sizeMax];
	_size = vec._size;
	for(i=0;i<_size;i++)
	{
		v[i] = vec.v[i];
	}

}

//Destructeur

template <class T>
Vecteur<T>::~Vecteur()
{
	#ifdef DEBUG
	cout << "Destructeur de Vecteur" << endl;
	#endif
	if(v!= NULL)
		delete[] v;
}

//operateur de surcharge

template <class T>
Vecteur<T>& Vecteur<T>::operator=(const Vecteur<T>& vec)
{
	int i;
	_sizeMax = vec._sizeMax;
	v = new T[vec._sizeMax];
	_size = vec._size;
	for(i=0;i<_size;i++)
	{
		v[i] = vec.v[i];
	}
	return (*this);

}

template <class T>
T& Vecteur<T>::operator[](int ref)
{
	return v[ref];
}

//Fonction

template <class T>
void Vecteur<T>::insere(const T& val) // permettant d’insérer un nouvel élément à la fin du vecteur, c’est-à-dire à la première case libre.
{
	#ifdef DEBUG
	cout << "Insertion de Vecteur" << val << endl;
	#endif
	v[size()]=val;
	_size++;
}

template <class T>
void Vecteur<T>::Affiche() // permettant de parcourir le vecteur et d’afficher chaque élément de celui-ci.
{
	int i;
	for(i=0;i<size();i++)
	{
		cout << "N°" << i << " : " << v[i] << endl;
	}
}

template <class T>
int Vecteur<T>::size() // retournant le nombre d’éléments présents dans le vecteur.
{
	return _size;
}

template <class T>
int Vecteur<T>::sizeMax() // retournant la capacité du vecteur (_sizeMax).
{
	return _sizeMax;
}

// retire() permet de supprimer et de retourner l’élément situé à
// l’indice ind dans le vecteur. Les valeurs possibles pour ind sont 0, …, size()-1. Après
// suppression d’un élément, tous les éléments situés à droite de celui-ci doivent être décalés
// vers la gauche, et la variable _size doit être mise à jour.
template <class T>
T Vecteur<T>::retire(int ind)
{
	int i;
	T ret;
	ret = v[ind];
	for(i=ind;i<_size-1;i++)
	{
		v[i] = v[i+1];
	}
	_size--;
	return ret;

}

// Instanciation des templates

template class Vecteur<int>;
template class Vecteur<Client>;
template class Vecteur<Modele>;
template class Vecteur<Option>;
template class Vecteur<Employe>;

