#include "Setting.h"

Setting::Setting()
{
	general = new General();
	sound = new Sound();
	display = new Display();
}
Setting::~Setting()
{
}

void Setting::setDisplay(Display* display)
{
	this->display = display;
}
void Setting::setGeneral(General* general)
{
	general = general;
}
void Setting::setSound(Sound* sound)
{
	this->sound = sound;
}

General* Setting::getGeneral()
{
	return this->general;
}
Display* Setting::getDisplay()
{
	return this->display;
}
Sound* Setting::getSound()
{
	return this->sound;
}

void Setting::inputInformationJoint()
{
	string checkName = "(([A-Za-z]+) ([A-Za-z]+))+|[A-Za-z]+";
	string checkEmail = "(\\w+)(\\.|_)?(\\W*)@((\\w+){3})(\\.(\\w+){3})";
	string checkKeyNumber = "[0-9]{8}";
	string checkOdoRemind = "^[0-9]*$";

	cout << "    Ower name: ";
	setName(checkDataString(checkName));

	cout << "    Email: ";
	setEmail(checkDataString(checkEmail));

	cout << "    Key number: ";
	setKeyNumber(checkDataString(checkKeyNumber));

	cout << "    ODO number: ";
	setOdoNumber(checkDataNum(checkOdoRemind));

	cout << "    Remind service (km): ";
	setRemindService(checkDataNum(checkOdoRemind));
}
void Setting::printInformatonJoint()
{
	cout << setw(20) << left << getName() << setw(20) << left << getEmail()
		<< setw(20) << left << getKeyNumber() << setw(10) << left << getOdoNumber()
		<< setw(15) << left << getRemindService() << endl;
}