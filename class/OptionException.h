#ifndef OPTIONEXCEPTION_H
#define OPTIONEXCEPTION_H

#include <string>
#include "Exception.h"

using namespace std;


class OptionException : public Exception
{
// private:
// 	string mes;
public:
	
	//contruction
	OptionException();
// 	OptionException(string m);
 	//OptionException(const OptionException& e);
	//destructeur
	//~OptionException();
	
};

#endif