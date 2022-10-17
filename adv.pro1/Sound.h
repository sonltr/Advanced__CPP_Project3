#pragma once
#ifndef SOUND_H_
#define SOUND_H_
#include "Validate.h"
#include<iomanip>
#include <iostream>
#include <string>
using namespace std;
class Sound
{
private:
    int media;
    int call;
    int navigation;
    int notification;
public:
    Sound();
    Sound(int, int, int, int);
    ~Sound();

    void setMedia(int);
    void setCall(int);
    void setNavigation(int);
    void setNotification(int);

    int getMedia();
    int getCall();
    int getNavigation();
    int getNotification();

    void inputSound();  
    void printSound();  
};
#endif // SOUND_H_

