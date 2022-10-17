#ifndef MENU_H_
#define MENU_H_
#include "Setting.h"
#include "Validate.h"
#include <vector>
#include "CommonInfo.h"
#include <iostream>
#include <regex>
class Menu
{
public:
	Menu();
	~Menu();

	void menu(); 
	//menu select setting type 
	void InputSettingInformation();  
	//menu select each print type
	void PrintSettingInformation();  
	// input information Display,Sound or General type
	void inputSettingDisplay();
	void inputSettingSound();
	void inputSettingGeneral();
	// print information Display,Sound,General or all type
	void printAll();  
	void printDisplay();  
	void printSound();  
	void printGeneral();  
	// print D,S or G by name or key
	void PrintDisplayName();
	void PrintDisplayKey();
	void PrintSoundName();
	void PrintSoundKey();
	void PrintGeneralName();
	void PrintGeneralKey();
	void PrintAllName();
	void PrintAllKey();
	// read, write file
	void loadData();
	void saveData();

	template<typename T>
	void show_general(string filename, T &t);
	const vector<string> explode(const string& s, const char& c);
	
	//sort cars by name or key
	template<class T>
    void sortNameOrKeyNumber(T &t,string s);
	//print notice Car is already or new
	void exist(Setting* temp);
	// Compare if the key is the same, update
	void compareKeyNumber(Setting* temp);
	//show
	void showInforDisplay();
	void showInforSound();
	void showInforGeneral();
	void showAllSetting();
	//check
	bool checkYorN(); 
	void checkEnough100CarsYet();
	//check whether the Car has data or not. if not, enter the data (num = 0;)
	void checkData();
private:
	vector<Setting*> listCar;
	vector<CommonInfo> timezoneList;
	vector<CommonInfo> languageList;
	//setting D or S or G to update if key already exists
	int setUpdate;
};
bool sortNameGeneral(CommonInfo& a_string, CommonInfo& b_string);
bool sortCarName(Setting *carInfo_i, Setting *carInfo_j);
bool sortCarKey(Setting *carInfo_i, Setting *carInfo_j);
#endif //MENU_H_