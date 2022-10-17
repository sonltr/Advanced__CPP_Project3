#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "Validate.h"
#include <iomanip>
#include <iostream>
using namespace std;

class Display
{
private:
	int lightLevel;
	int screenLight;
	int taploLight;
public:
	Display();
	Display(int, int, int);
	~Display();
	void setLightLevel(int);
	void setScreenLight(int);
	void setTaploLight(int);
	int getLightLevel();
	int getScreenLight();
	int getTaploLight();
	void inputDisplay(); 
	void printDisplay(); 
};
#endif /* DISPLAY_H_ */