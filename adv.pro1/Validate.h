#pragma once
#ifndef VALIDATE_H
#define VALIDATE_H
#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

bool checkRegex(string, string);
int checkDataNum(string str);
string checkDataString(string str);
bool checkEmptyFile(ifstream& pFile);
int checkInputLorT(int n);
#endif //VALIDATE_H