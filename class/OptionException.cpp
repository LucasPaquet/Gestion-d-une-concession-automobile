#include <string>
#include <iostream>

#include "OptionException.h"

//Constructeur
OptionException::OptionException() : Exception()
{
  #ifdef DEBUG
  cout << "Contructeur par default de OptionException" << endl;
  #endif
}

OptionException::OptionException(string m) : Exception(m)
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation de OptionException : " << m << "<->" << message << endl;
  #endif
}

OptionException::OptionException(const OptionException& e)
{
  #ifdef DEBUG
  cout << "Contructeur de copie de OptionException : " << e.message <<endl;
  #endif
  message = e.message;
}
// Destructeur
OptionException::~OptionException()
{
	#ifdef DEBUG
	cout << "Destructeur de OptionException" << endl;
	#endif
}


