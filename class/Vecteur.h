#ifndef VECTEUR_H
#define VECTEUR_H

#include <string>

#include "Client.h"

using namespace std;

template <class T> class Iterateur;

template<class T> 
class Vecteur
{
protected:
    T * v;
    int _sizeMax;
    int _size;
public:
    //constructeur 

    Vecteur();
    Vecteur(int i);
    Vecteur(const Vecteur<T>& v);

    //destructeur

    ~Vecteur();

    //operateur de surcharges

    Vecteur<T>& operator=(const Vecteur<T>& vec);
    T& operator[](int ref);

    //Fonction

    void insere(const T & val);
    void Affiche();
    int size();
    int sizeMax();
    T retire(int ind);

    friend class Iterateur<T>;
};

#endif
