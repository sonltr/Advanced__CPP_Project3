#include "Validate.h"

bool checkEmptyFile(ifstream& pFile)  
{
	if (pFile.peek() == ifstream::traits_type::eof())
	{
		return true;
	}
	else return false;
}

int checkDataNum(string str)
{
	string input = "";
	int iTemp;
	bool check = true;
	while(1)
	{
		try {
			getline(cin, input);
			if (checkRegex(input, str) || stoi(input) > 10 || stoi(input) < 0)
			{	
				iTemp = stoi(input);
				break;
			}
			else
			{ 
				throw exception();
			}
		}
		catch (const exception ex)
		{
			cout << "-->Please again: ";
		}
	} 
	return iTemp;
}
string checkDataString(string str)
{
	string strTemp = "";
	bool check = true;
	do {
		try {
			getline(cin, strTemp);
			if (!checkRegex(strTemp, str))   
			{
				cout << "-->Please again: ";
				check = false;
			}
			else
			{
				throw 909;

			}
		}
		catch (...)
		{
			check = true;
		}
	} while (!check);
	return strTemp;
}

// check the input character according to the regex
bool checkRegex(string data, string f)
{
	regex check(f);
	if (regex_match(data, check))  
	{
		return true;
	}
	else  
	{
		return false;   
	}
}
int checkInputLorT(int length)
{
	regex pattern("[0-9]+");
	string input;
	int numberReturn = 0;
	while (1) {
		
		getline(cin, input);
		try
		{
			if (regex_match(input, pattern) && stoi(input) <= length && stoi(input) > 0) {
				numberReturn = stoi(input);
				break;
			}
			else
			{
				throw exception();
			}
		}
		catch (const exception ex)
		{
			cout << "YOUR SELECTION: ";
		}
	}
	return numberReturn;
}
