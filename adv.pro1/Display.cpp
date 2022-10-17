#include "Display.h"

Display::Display()
{
	lightLevel = 0;
	screenLight = 0;
	taploLight = 0;
}
Display::Display(int lightLevel, int screenLight, int taploLight)
{
	this->lightLevel = lightLevel;
	this->screenLight = screenLight;
	this->taploLight = taploLight;
}
Display::~Display()
{
}

void Display::setLightLevel(int lightLevel)
{
	this->lightLevel = lightLevel;
}
void Display::setScreenLight(int screenLight)
{
	this->screenLight = screenLight;
}
void Display::setTaploLight(int taploLight)
{
	this->taploLight = taploLight;
}

int Display::getLightLevel()
{
	return this->lightLevel;
}
int Display::getScreenLight()
{
	return this->screenLight;
}
int Display::getTaploLight()
{
	return this->taploLight;
}


void Display::inputDisplay()
{
	string re_display = "[0-9]+";
	cout << "    Media: ";
	setLightLevel(checkDataNum(re_display));
	cout << "    Screen light level: ";
	setScreenLight(checkDataNum(re_display));
	cout << "    Taplo light level: ";
	setTaploLight(checkDataNum(re_display));
}
void Display::printDisplay()
{
	cout << setw(20) << left << getLightLevel() << setw(20) << left << getScreenLight()
		<< setw(30) << left << getTaploLight() << endl << endl;
}



