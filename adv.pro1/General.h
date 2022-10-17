#ifndef GENERAl_H_
#define GENERAL_H_
#define _CRT_SECURE_NO_WARNINGS
#include "Validate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class General
{
private:
	string timeZone;
	string language;
public:
	General();
	General(string, string);
	~General();

	void setTimeZone(string);
	void setLanguage(string);

	string getTimeZone();	
	string getLanguage();

	void inputGeneral();  
	void printGeneral();  
};
#endif  //GENERAL_H_ 