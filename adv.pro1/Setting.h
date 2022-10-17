#pragma once
#ifndef SETTING_H_
#define SETTING_H_
#include"General.h"
#include "Display.h"
#include "Sound.h"
#include "Car.h"
#include "Validate.h"

class Setting : public Car
{
private:
	General* general;
	Sound* sound;
	Display* display;
public:
	Setting();
	~Setting();
	void setGeneral(General* general);
	void setDisplay(Display* display);
	void setSound(Sound* sound);
	Sound* getSound();
	Display* getDisplay();
	General* getGeneral();
	void inputInformationJoint();
	void printInformatonJoint();
};
#endif /* SETTING_H_ */



