#ifndef ITERATEUR_H
#define ITERATEUR_H

#include <string>

using namespace std;

#include "Vecteur.h"

template<class T> class Iterateur
{
private:
    Vecteur<T>& p;
    T * pData;
public:
    //constructeur 
    Iterateur(Vecteur<T>& l);

    //destructeur

    ~Iterateur();

    //operateur de surcharges
    bool operator++();
    bool operator++(int);

    operator T();

    //Fonction

    bool end() const;
    void reset();

};

#endif