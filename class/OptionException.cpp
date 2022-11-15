#include <string>
#include <iostream>

#include "OptionException.h"

//Constructeur
OptionException::OptionException()
{
  #ifdef DEBUG
  cout << "Contructeur par default de OptionException" << endl;
  #endif
  cout << "Contructeur par default de OptionException" << endl;
  //mes = "rien";
}

// OptionException::OptionException(string m)// : Exception(m)
// {
//   #ifdef DEBUG
//   cout << "Contructeur d'initialisation" << endl;
//   #endif
//   cout << "Contructeur par default de OptionException" << endl;
//   mes = m;
// }

// OptionException::OptionException(const OptionException& e)
// {
//   #ifdef DEBUG
//   cout << "Contructeur de copie" << endl;
//   #endif
//   cout << "Contructeur par default de copie" << endl;
// }
// // Destructeur
// OptionException::~OptionException()
// {
// 	#ifdef DEBUG
// 	cout << "Destructeur" << endl;
// 	#endif
// 	cout << "Contructeur par default de OptionException" << endl;
// }