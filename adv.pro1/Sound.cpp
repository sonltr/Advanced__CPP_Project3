#include "Sound.h"

using namespace std;

Sound::Sound()
{
	this->media = 0;
	this->call = 0;
	this->navigation = 0;
	this->notification = 0;
}
Sound::Sound(int media, int call, int navigation, int notification)
{
	this->media = media;
	this->call = call;
	this->navigation = navigation;
	this->notification = notification;
}
Sound::~Sound()
{
}

void Sound::setMedia(int media)
{
	this->media = media;
}
void Sound::setCall(int call)
{
	this->call = call;
}
void Sound::setNavigation(int navigation)
{
	this->navigation = navigation;
}
void Sound::setNotification(int notification)
{
	this->notification = notification;
}

int Sound::getMedia()
{
	return this->media;
}
int Sound::getCall()
{
	return this->call;
}
int Sound::getNavigation()
{
	return this->navigation;
}
int Sound::getNotification()
{
	return this->notification;
}

void Sound::inputSound()
{
	string re_sound = "[1-9]|[1-9][0-9]*";
	cout << "    Light level: ";
	setMedia(checkDataNum(re_sound));
	cout << "    Call: ";
	setCall(checkDataNum(re_sound));
	cout << "    Navigation: ";
	setNavigation(checkDataNum(re_sound));
	cout << "    Notification: ";
	setNotification(checkDataNum(re_sound));
}
void Sound::printSound()
{
	cout << setw(20) << left << getMedia() << setw(20) << left << getCall()
		<< setw(30) << left << getNavigation() << setw(30) << left << getNotification() 
		<< endl << endl;
}




