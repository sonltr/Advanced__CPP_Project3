#include "General.h"
#include "CommonInfo.h"
General::General()
{
	this->timeZone = "GMT-12:00";
	this->language = "English";
}
General::General(string m_timeZone, string m_language)
{
	this->timeZone = m_timeZone;
	this->language = m_language;
}
General::~General()
{
}

void General::setTimeZone(string timeZone)
{
	this->timeZone = timeZone;
}
void General::setLanguage(string language)
{
	this->language = language;
}

string General::getTimeZone()
{
	return this->timeZone;
}
string General::getLanguage()
{
	return this->language;
}

void General::inputGeneral()
{
} 
void General::printGeneral()
{
	cout << setw(20) <<left << getTimeZone()
		<< setw(20) << left << getLanguage() << endl << endl;
}




