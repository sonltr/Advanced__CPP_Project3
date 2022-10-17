#include "Menu.h"

using namespace std;
Menu::Menu()
{
}

Menu::~Menu()
{
}



bool sortCarName(Setting* carInfo_i, Setting* carInfo_j) {
    return (carInfo_i->getName() < carInfo_j->getName());
}
bool sortCarKey(Setting* carInfo_i, Setting* carInfo_j) {
    return (carInfo_i->getKeyNumber() < carInfo_j->getKeyNumber());
}
void Menu::PrintDisplayName() {
    system("cls");
    sortNameOrKeyNumber<vector<Setting*>>(listCar, "Name");  
    showInforDisplay();
}
void Menu::PrintDisplayKey() {
    system("cls");
    sortNameOrKeyNumber<vector<Setting*>>(listCar, "KeyNumber");
    showInforDisplay();
}
void Menu::PrintSoundName() {
    system("cls");
    sortNameOrKeyNumber<vector<Setting*>>(listCar, "Name");
    showInforSound();
}
void Menu::PrintSoundKey() {
    system("cls");
    sortNameOrKeyNumber<vector<Setting*>>(listCar, "KeyNumber");
    showInforSound();
}
void Menu::PrintGeneralName() {
    system("cls");
    sortNameOrKeyNumber<vector<Setting*>>(listCar, "Name");
    showInforGeneral();
}
void Menu::PrintGeneralKey() {
    system("cls");
    sortNameOrKeyNumber<vector<Setting*>>(listCar, "KeyNumber");
    showInforGeneral();
}
void Menu::PrintAllName() {
    system("cls");
    sortNameOrKeyNumber<vector<Setting*>>(listCar, "Name");
    showAllSetting();
}
void Menu::PrintAllKey() {
    system("cls");
    sortNameOrKeyNumber<vector<Setting*>>(listCar, "KeyNumber");
    showAllSetting();
}
void Menu::checkData()
{
    if (listCar.size() == 0)
    {
        system("cls");
        //no data, user to enter data before print
        cout << "-->No data yet " << endl;
        cout << "-->Please input Data! " << endl;
        menu();
    }
}
void Menu::checkEnough100CarsYet()
{
    if (listCar.size() > 100)
    {
        cout << "100 cars limit -> can't enter more";
        menu();
    } 
}
void Menu::menu()  
{
    int SelectMenu1 = 0;
    string re_num = "[1-3]{1}";
    cout << "-----SELECT menu 1-----" << endl;
    cout << "1. Input setting information" << endl;
    cout << "2. Print setting information" << endl;
    cout << "3. Exit" << endl;
    cout << "Your selction:  ";
    
    SelectMenu1 = checkDataNum(re_num);
    switch (SelectMenu1)
    {
    case 1:
        system("cls");
        InputSettingInformation(); 
        break;
    case 2:
        system("cls");
        PrintSettingInformation(); 
        break;
    case 3:
        system("cls");
        cout << "---GOOD BYE---!!!";
        exit(0);
    default:
        break;
    }
}
void Menu::InputSettingInformation()  
{

    int SelectMenu2 = 0;
    string re_num2 = "[0-3]{1}";
    cout << "-----SELECT menu 2-----" << endl;
    cout << "1. Input display setting  " << endl;
    cout << "2. Input sound setting  " << endl;
    cout << "3. Input general setting  " << endl;
    cout << "0. Exit" << endl;
    cout << "selction: ";

    SelectMenu2 = checkDataNum(re_num2);
    switch (SelectMenu2) {
    case 1: {
        system("cls");
        inputSettingDisplay();
        system("cls");
        menu();
        break;
    }
    case 2: {
        system("cls");
        inputSettingSound();
        system("cls");
        menu();
        break;
    }
    case 3: {
        system("cls");
        inputSettingGeneral();
        system("cls");
        menu();
        break;
    }
    case 0:
        system("cls");
        menu();
        break;
    default:
    {
        break;
    }
    }

}

void Menu::PrintSettingInformation()  
{
    //check whether the Car has data or not. if not, enter the data (num = 0;)
    checkData();

    int SelectMenu3 = 0;
    cout << "---SELECT MENU 3---\n";
    cout << "1. Print Display setting information\n";
    cout << "2. print Sound setting information\n";
    cout << "3. Print General setting information\n";
    cout << "4. Print all setting information\n";
    cout << "5. Exit\n";
    cout << "Your selection: ";

    string re_num3 = "[1-5]{1}";
    SelectMenu3 = checkDataNum(re_num3);
    switch (SelectMenu3) {
    case 1: {
        system("cls");
        printDisplay();
        PrintSettingInformation();
        break;
    }
    case 2: {
        system("cls");
        printSound();
        PrintSettingInformation();
        break;
    }
    case 3: {
        system("cls");
        printGeneral();
        PrintSettingInformation();
        break;
    }
    case 4:
        system("cls");
        printAll();
        PrintSettingInformation();
        break;
    case 5:
        system("cls");
        menu();
        break;
    default:
    {
        break;
    }
    }
}
void Menu::inputSettingDisplay()
{
    bool continueYorN = true;
    do
    {
        checkEnough100CarsYet();
        system("cls");
        //setting D or S or G to update if key already exists
        setUpdate = 1;  
        cout << "--- Input Display setting ---" << endl;
        cout << "Car index: " << listCar.size() + 1 << endl;
        Setting* temp = new Setting;
        temp->inputInformationJoint();
        //print an existing or new car notice
        exist(temp); 
        temp->getDisplay()->inputDisplay();
        //compare if already exists to update
        compareKeyNumber(temp);
        //write file
        saveData(); 
        //enter more?
        continueYorN = checkYorN();  
    } while (continueYorN);
}
void Menu::inputSettingSound()
{
    bool continueYorN = true;
    do
    {
        checkEnough100CarsYet();
        system("cls");
        //setting D or S or G to update if key already exists
        setUpdate = 2;   
        cout << "--- Input Sound setting ---" << endl;
        cout << "Car index: " << listCar.size() + 1 << endl;
        Setting* temp = new Setting;
        temp->inputInformationJoint();
        //print an existing or new car notice
        exist(temp);
        temp->getSound()->inputSound();
        //compare if already exists to update
        compareKeyNumber(temp); 
        //write file
        saveData(); 
        //enter more? 
        continueYorN = checkYorN();  
    } while (continueYorN);
}
void Menu::inputSettingGeneral()
{
    bool continueYorN = true;
    do
    {
        checkEnough100CarsYet();
        system("cls");
        //setting D or S or G to update if key already exists
        setUpdate = 3;
        Setting* temp = new Setting;
        cout << "--- Input General setting ---" << endl;
        cout << "Car index: " << listCar.size() + 1 << endl;
        temp->inputInformationJoint();
        //print an existing or new car notice
        exist(temp);

        //timezones.txt
        show_general<vector<CommonInfo>>("timezones.txt", timezoneList);//<vector<CommonInfo>>??????
        cout << "YOUR SELECTION: "; 
        int timeZone_count = checkInputLorT(timezoneList.size()) - 1;;
        temp->getGeneral()->setTimeZone(timezoneList[timeZone_count].getNumber());
        //languages.txt
        show_general<vector<CommonInfo>>("languages.txt", languageList);
        cout << "YOUR SELECTION: "; 
        int language_count = checkInputLorT(languageList.size()) - 1;
        temp->getGeneral()->setLanguage(languageList[language_count].getName());
        //compare if already exists to update
        compareKeyNumber(temp);
        //write file
        saveData();
        //enter more?
        continueYorN = checkYorN();
    } while (continueYorN);
}
void Menu::printAll() 
{
    cout << "--- SELECT MENU PRINT ALL---" << endl;
    cout << "1. print all setting by name" << endl
        << "2. print all setting by keynumber" << endl
        << "0. exit" << endl
        << "your selection: ";
    string re_num = "[0-2]{1}";
    int SelectMenu = 0;
    SelectMenu = checkDataNum(re_num);
    switch (SelectMenu)
    {
    case 1:
        system("cls");
        PrintAllName();
        PrintSettingInformation();
        break;
    case 2:
        system("cls");
        PrintAllKey();
        PrintSettingInformation();
        break;
    case 0:
        system("cls");
        PrintSettingInformation();
    default:
        break;
    }
}
void Menu::printDisplay()  
{
    cout << "--- SELECT MENU PRINT DISPLAY---" << endl;
    cout << "1. print display setting by name" << endl
        << "2. print display setting by keynumber" << endl
        << "0. exit" << endl
        << "your selection: ";
    string re_num = "[0-2]{1}";
    int SelectMenu = 0;
    SelectMenu = checkDataNum(re_num);
    switch (SelectMenu)
    {
    case 1:
        system("cls");
        PrintDisplayName();
        break;
    case 2:
        system("cls");
        PrintDisplayKey(); 
        break;
    case 0:
        system("cls");
        PrintSettingInformation();
    default:
        break;
    }
}
void Menu::printSound() 
{
    cout << "--- SELECT MENU PRINT SOUND---" << endl;
    cout << "1. print sound setting by name" << endl
        << "2. print sound setting by keynumber" << endl
        << "0. exit" << endl
        << "your selection: ";
    string re_num = "[0-2]{1}";
    int SelectMenu = 0;
    SelectMenu = checkDataNum(re_num);
    switch (SelectMenu)
    {
    case 1:
        system("cls");
        PrintSoundName();
        break;
    case 2:
        system("cls");
        PrintSoundKey();
        break;
    case 0:
        system("cls");
        PrintSettingInformation();
    default:
        break;
    }
}
void Menu::printGeneral()  
{
    cout << "--- SELECT MENU PRINT GENERAL---" << endl;
    cout << "1. print general setting by name" << endl
        << "2. print general setting by keynumber" << endl
        << "0. exit" << endl
        << "your selection: ";
    string re_num = "[0-2]{1}";
    int SelectMenu = 0;
    SelectMenu = checkDataNum(re_num);
    switch (SelectMenu)
    {
    case 1:
        system("cls");
        PrintGeneralName();
        break;
    case 2:
        system("cls");
        PrintGeneralKey();
        break;
    case 0:
        system("cls");
        PrintSettingInformation();
    default:
        break;
    }
}

bool Menu::checkYorN()  
{
    cout << "Will you input for car " << " " << "(y/n)" << endl;
    bool status = true;
    string YorN = "y|n|Y|N";
    string b = checkDataString(YorN);
    if (b == "y" || b == "yes")
    {
        status = true;
        return status;
    }
    if (b == "n" || b == "No")
    {
        status = false;
        return status;
    }
}

// function compare and update
void Menu::compareKeyNumber(Setting* temp)  
{
    int update = 0; 
    if (listCar.size() > 0)
    {
        for (size_t i = 0; i < listCar.size(); i++)
        {
            //Setting* carInfo = listCar[i];
            if (listCar[i]->getKeyNumber() == temp->getKeyNumber())
            {
                listCar[i]->setName(temp->getName());
                listCar[i]->setEmail(temp->getEmail());
                listCar[i]->setOdoNumber(temp->getOdoNumber());
                listCar[i]->setRemindService(temp->getRemindService());
                switch (setUpdate)
                {
                    
                case 1:
                    update = 1;
                    listCar[i]->getDisplay()->setLightLevel(temp->getDisplay()->getLightLevel());
                    listCar[i]->getDisplay()->setTaploLight(temp->getDisplay()->getTaploLight());
                    listCar[i]->getDisplay()->setScreenLight(temp->getDisplay()->getScreenLight());
                    break;
                case 2:
                    update = 1;
                    listCar[i]->getSound()->setMedia(temp->getSound()->getMedia());
                    listCar[i]->getSound()->setCall(temp->getSound()->getCall());
                    listCar[i]->getSound()->setNavigation(temp->getSound()->getNavigation());
                    listCar[i]->getSound()->setNotification(temp->getSound()->getNotification());
                    break;
                case 3:
                    update = 1;        
                    listCar[i]->getGeneral()->setLanguage(temp->getGeneral()->getLanguage());
                    listCar[i]->getGeneral()->setTimeZone(temp->getGeneral()->getTimeZone());
                    break;
                }
            }
        }
        if (update == 0)
        {
            listCar.push_back(temp);
        }
    }
    // listCar.size() = 0
    else 
    {
        listCar.push_back(temp);
    }
}
// sort by key or name. functiom generic 
template<class T>
void Menu::sortNameOrKeyNumber(T &t,string s) //sap xep theo ten
{
    if (t.size() > 1)
    {
        if (s == "Name")
        {
            sort(t.begin(), t.end(), sortCarName);
        }
        else if (s == "KeyNumber")
        {
            sort(t.begin(), t.end(), sortCarKey);
        }
    }
}
void Menu::exist(Setting* temp) 
{
    vector<string>::iterator it;
    vector<string> list;
    for (auto item : listCar)
    {
        list.push_back(item->getKeyNumber());
    }
    it = find(list.begin(), list.end(), temp->getKeyNumber());
    if (it != list.end())
    {
        cout << "    ===> This car already existed, data will be overriten" << endl;
    }
    else
    {
        if (listCar.size() != 0)
        {
            cout << "    ===>This is a new car, data will be appended to your list" << endl;
        }
    }
}

void Menu::showInforDisplay()
{
    
    for (size_t i = 0; i < listCar.size(); i++)
    {
        cout << "---Common " << i + 1 << ":" << endl;
        cout << setw(20) << left << "Owner name" << setw(20) << left << "Email"
            << setw(20) << left << "Key" << setw(10) << left << "ODO"
            << setw(15) << left << "service" << endl;
        listCar[i]->printInformatonJoint();
        cout << "---Display: " << endl;
        cout << setw(20) << left << "Light level" << setw(20) << left << "Screen Light level" 
            << setw(30) << left << "Taplo light level" << endl;
        listCar[i]->getDisplay()->printDisplay();
        cout << "****************************************************"
            << "*****************************************************" << endl;
    }
}
void Menu::showInforSound()
{
    for (size_t i = 0; i < listCar.size(); i++)
    {
        cout << setw(20) << left << "Owner name" << setw(20) << left << "Email"
            << setw(20) << left << "Key" << setw(10) << left << "ODO"
            << setw(15) << left << "service" << endl;
        listCar[i]->printInformatonJoint();
        cout << "---Sound: " << endl;
        cout << setw(20) << left << "Media" << setw(20) << left << "Call"
            << setw(30) << left << "Navigation" << setw(20) << left << "Notification" << endl;
        listCar[i]->getSound()->printSound();
        cout << "****************************************************"
            << "*****************************************************" << endl;
    }

}
void Menu::showInforGeneral()
{
    for (size_t i = 0; i < listCar.size(); i++)
    {
        cout << setw(20) << left << "Owner name" << setw(20) << left << "Email"
            << setw(20) << left << "Key" << setw(10) << left << "ODO" 
            << setw(15) << left << "service" << endl;
        listCar[i]->printInformatonJoint();
        cout << "---General:" << endl;
        cout << setw(20) << left << "TimeZone" << setw(20) << left << "Language" << endl;
        listCar[i]->getGeneral()->printGeneral();
        cout << "****************************************************"
            << "*****************************************************" << endl;
    }

}
void Menu::showAllSetting()
{
    for (size_t i = 0; i < listCar.size(); i++)
    {
        cout << setw(20) << left << "Owner name" << setw(20) << left << "Email"
            << setw(20) << left << "Key" << setw(10) << left << "ODO"
            << setw(15) << left << "service" << endl;
        listCar[i]->printInformatonJoint();
        cout << "---Display: " << endl;
        cout << setw(20) << left << "Light level" << setw(20) << left << "Screen Light level"
            << setw(30) << left << "Taplo light level" << endl;
        listCar[i]->getDisplay()->printDisplay();
        cout << "---Sound: " << endl;
        cout << setw(20) << left << "Media" << setw(20) << left << "Call"
            << setw(30) << left << "Navigation" << setw(20) << left << "Notification" << endl;
        listCar[i]->getSound()->printSound();
        cout << "---General:" << endl;
        cout << setw(20) << left << "TimeZone" << setw(20) << left << "Language" << endl;
        listCar[i]->getGeneral()->printGeneral();
        cout << "****************************************************"
            << "*****************************************************" << endl;
    }

}
const vector<string> Menu::explode(const string& s, const char& c)
{
    string buff;
    vector<string> v;
    for (auto n : s)
    {
        if (n != c)
            buff += n;
        else if (n == c && buff != "")
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "")
        v.push_back(buff);
    return v;
}
bool sortNameGeneral(CommonInfo& a_string, CommonInfo& b_string)
{
    return (a_string.getName() < b_string.getName());
}
//show sorted timezones or languages
template<typename T>
void Menu::show_general(string filename, T &t){
	ifstream file;
    file.open(filename, ios::in);
    try {
        if (file.is_open()) 
		{
            string dataLine;
            CommonInfo com;
            vector<string> temp;

            while (getline(file, dataLine)) {
                temp = explode(dataLine, '/');
				if (temp.size() >= 2) {
                    com.setNumber(temp[0]);
                    com.setName(temp[1]);
                }
                t.push_back(com);
            }
            file.close();
        }
        else
        {
            // another error warning when opening the file
            throw exception(); 
        }
    }
    catch (const exception)  
    {
        cerr << "Khong the mo file:" <<filename<<endl;

    }
	vector <string> names;
	for (int i = 0; i < t.size(); i++) {
		names.push_back(t[i].getName());
	}
	sort(t.begin(), t.end(),sortNameGeneral);
	if(filename=="languages.txt")
	{
		for (int i = 0; i < t.size(); i++)
		{
			cout << i + 1 << " :" << t[i].getName() << endl;
		}
	}
	else if(filename=="timezones.txt")
	{
		for (int i = 0; i < t.size(); i++)
		{
			cout << i + 1 << " : " << t[i].getNumber() << "-" << t[i].getName() << endl;
		}
	}
}
void Menu::loadData()
{
    ifstream settingInput;
    try
    {
        settingInput.open("setting.txt", ios::in);
        if (checkEmptyFile(settingInput))
        {
            throw exception();
        }
        else if (settingInput.is_open())
        {
            int dem = 0;
            while (!settingInput.eof())
            {
                string tam;
                Setting* temp = new Setting;
                string name, email, keyNumber, language, timeZone;
                string odoNumber, remindService;
                string lightLevel, screenLight, taploLight, media, call, navigation, notification;

                //read information joint
                getline(settingInput, tam, ':');
                getline(settingInput, name, ',');
                getline(settingInput, email, ',');
                getline(settingInput, keyNumber, ',');
                getline(settingInput, odoNumber, ',');
                getline(settingInput, remindService, ';');

                //read information General
                getline(settingInput, tam, ':');
                getline(settingInput, language, ',');
                getline(settingInput, timeZone, ';');

                //read information Sound
                getline(settingInput, tam, ':');
                getline(settingInput, media, ',');
                getline(settingInput, call, ',');
                getline(settingInput, navigation, ',');
                getline(settingInput, notification, ';');

                //read information Display
                getline(settingInput, tam, ':');
                getline(settingInput, lightLevel, ',');
                getline(settingInput, screenLight, ',');
                getline(settingInput, taploLight, ';');
                getline(settingInput, tam);

                // data given from file to temp object
                temp->setName(name);
                temp->setEmail(email);
                temp->setKeyNumber(keyNumber);
                temp->setOdoNumber(stoi(odoNumber));
                temp->setRemindService(stoi(remindService));
                temp->getDisplay()->setLightLevel(stoi(lightLevel));
                temp->getDisplay()->setScreenLight(stoi(screenLight));
                temp->getDisplay()->setTaploLight(stoi(taploLight));
                temp->getSound()->setCall(stoi(call));
                temp->getSound()->setMedia(stoi(media));
                temp->getSound()->setNavigation(stoi(navigation));
                temp->getSound()->setNotification(stoi(notification));
                temp->getGeneral()->setLanguage(language);
                temp->getGeneral()->setTimeZone(timeZone);

                // add object to list
                listCar.push_back(temp);
            }
            settingInput.close();
        }
    }
	catch (const exception ex)  
    {
    }
}

void Menu::saveData()
{
    ofstream settingOutput("setting.txt", ios::out);
    try
    {
        if (settingOutput.is_open())
        {
            for (size_t i = 0; i < listCar.size(); i++) 
            {
                settingOutput << "Common:"
                    << listCar[i]->getName() << ","
                    << listCar[i]->getEmail() << ","
                    << listCar[i]->getKeyNumber() << ","
                    << listCar[i]->getOdoNumber() << ","
                    << listCar[i]->getRemindService() << ";"
                    << "General:"
                    << listCar[i]->getGeneral()->getLanguage() << ","
                    << listCar[i]->getGeneral()->getTimeZone() << ";"
                    << "Sound:"
                    << listCar[i]->getSound()->getMedia() << ","
                    << listCar[i]->getSound()->getCall() << ","
                    << listCar[i]->getSound()->getNavigation() << ","
                    << listCar[i]->getSound()->getNotification() << ";"
                    << "Display:"
                    << listCar[i]->getDisplay()->getLightLevel() << ","
                    << listCar[i]->getDisplay()->getScreenLight() << ","
                    << listCar[i]->getDisplay()->getTaploLight() << ";" << endl;
            }
            settingOutput.close();
        }
        else
        {
            throw exception();
        }
    }
    catch (...)
    {
        cout << "Loi ghi file!" << endl;
    }

}
