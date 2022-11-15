#include <string>
#include <iostream>

#include "Exception.h"

//Constructeur
Exception::Exception()
{
  #ifdef DEBUG
  cout << "Contructeur par default de Exception" << endl;
  #endif
  message = "Message de base";
}

Exception::Exception(string m)
{
  #ifdef DEBUG
  cout << "Contructeur d'initialisation" << endl;
  #endif
  message = m;
}

// Exception::Exception(const Exception& e)
// {
//   #ifdef DEBUG
//   cout << "Contructeur de copie" << endl;
//   #endif
//   message = e.message;
  
// }
// // Destructeur
// Exception::~Exception()
// {
// 	#ifdef DEBUG
// 	cout << "Destructeur" << endl;
// 	#endif
// }


//setXXX et getXXX

string Exception::getMessage() const {return message;}
void Exception::setMessage(string m) {message = m;}