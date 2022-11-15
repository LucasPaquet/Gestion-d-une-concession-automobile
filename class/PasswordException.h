#ifndef PASSWORDEXCEPTION_H
#define PASSWORDEXCEPTION_H

#include <string>
#include "Exception.h"

using namespace std;


class PasswordException : public Exception
{
private:
	int code;
public:
	//contruction
	PasswordException();
	// PasswordException(string m);
	// PasswordException(const PasswordException& e);
	// //destructeur
	// ~PasswordException();

	//setXXX et getXXX
	void setCode(int i);
	int getCode() const;
	
};

#endif