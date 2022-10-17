#ifndef CAR_H_
#define CAR_H_
#include <iostream>
#include <iomanip>
#include <string>
#include "Validate.h"
using namespace std;

class Car
{
private:
	string name;
	string email;
	string keyNumber;
	int odoNumber;
	int remindService;
public:
	Car();
	Car(string, string, string, int, int);
	~Car();

	void setName(string);
	void setEmail(string);
	void setKeyNumber(string);
	void setOdoNumber(int);
	void setRemindService(int);

	string getName();
	string getEmail();
	string getKeyNumber();
	int getOdoNumber();
	int getRemindService();

	virtual void inputInformationJoint() = 0;  
	virtual void printInformatonJoint() = 0; 
};

#endif /* CAR_H_ */
