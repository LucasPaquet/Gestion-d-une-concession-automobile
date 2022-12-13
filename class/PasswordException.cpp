#include <string>
#include <iostream>

#include "PasswordException.h"

//Constructeur
PasswordException::PasswordException() : Exception()
{
  #ifdef DEBUG
  cout << "Contructeur par default de PasswordException" << endl;
  #endif
}

PasswordException::PasswordException(string m, int c) : Exception(m)
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif
  code = c;

}

PasswordException::PasswordException(int c) 
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif
  code = c;
  message = "ERRREUR";

}

PasswordException::PasswordException(const PasswordException& e)
{
  #ifdef DEBUG
  cout << "Contructeur de copie" << endl;
  #endif
  code = e.code;
  
}
// Destructeur
PasswordException::~PasswordException()
{
  #ifdef DEBUG
  cout << "Destructeur" << endl;
  #endif
}

//setXXX et getXXX

void PasswordException::setCode(int i)
{
  code = i;
}

int PasswordException::getCode() const
{
  return code;
}

string PasswordException::getMessage() const
{
  return message;
}