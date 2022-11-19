#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
using namespace std;

class Exception
{
protected:
	string message;

public:
	//constructeur 

	Exception();
	Exception(string m);
	Exception(const Exception& e);

	//destructeur

	~Exception();

	//SetXXX et getXXX

	string getMessage() const;
	void setMessage(string m);
	
};

#endif