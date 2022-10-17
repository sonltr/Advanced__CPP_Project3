#include "Car.h"

Car::Car()
{
	this->name = "";
	this->email = "";
	this->keyNumber = "";
	this->odoNumber = 0;
	this->remindService = 0;
}
Car::Car(string name, string email, string keyNumber, int odoNumber, int remindService)
{
	this->name = name;
	this->email = email;
	this->keyNumber = keyNumber;
	this->odoNumber = odoNumber;
	this->remindService = remindService;
}
Car::~Car()
{
}

void Car::setName(string name)
{
	this->name = name;
}
void Car::setEmail(string email)
{
	this->email = email;
}
void Car::setKeyNumber(string keyNumber)
{
	this->keyNumber = keyNumber;
}
void Car::setOdoNumber(int odoNumber)
{
	this->odoNumber = odoNumber;
}
void Car::setRemindService(int remindService)
{
	this->remindService = remindService;
}

string Car::getName()
{
	return this->name;
}
string Car::getEmail()
{
	return this->email;
}
string Car::getKeyNumber()
{
	return this->keyNumber;
}
int Car::getOdoNumber()
{
	return this->odoNumber;
}
int Car::getRemindService()
{
	return this->remindService;
}


