#include <string>
#include <iostream>

#include "PasswordException.h"

//Constructeur
PasswordException::PasswordException()
{
  #ifdef DEBUG
  cout << "Contructeur par default de PasswordException" << endl;
  #endif
}

// PasswordException::PasswordException(string m) : Exception(m)
// {
//   #ifdef DEBUG
//   cout << "Contructeur d'initialisation" << endl;
//   #endif
// }

// PasswordException::PasswordException(const PasswordException& e)
// {
//   #ifdef DEBUG
//   cout << "Contructeur de copie" << endl;
//   #endif
  
// }
// // Destructeur
// PasswordException::~PasswordException()
// {
//   #ifdef DEBUG
//   cout << "Destructeur" << endl;
//   #endif
// }

//setXXX et getXXX

PasswordException::setCode(int i)
{
  code = i;
}

int PasswordException::getCode() const
{
  return code;
}