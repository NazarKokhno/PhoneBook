#include <iostream>
#include <windows.h>
#include <cstring>
#include "Contact.h"

using namespace std;

Contact::Contact():Contact("Unknown", "No phone", "No phone", "No phone", "No Info")
{

}

Contact::Contact(const char* FullName):Contact(FullName, "No phone", "No phone", "No phone", "No Info")
{

}


Contact::Contact(const char* FullName, const char* HousePhone, const char* MobilePhone, const char* WorkPhone, const char* infoAboutContact)
{

	this->FullName = new char[strlen(FullName) + 1];
	strcpy_s(this->FullName, strlen(FullName) + 1, FullName);
	
	if (strlen(HousePhone) >= sizeof(this->HousePhone))
		strcpy_s(this->HousePhone, sizeof(this->HousePhone), "No phone");
	else
		strcpy_s(this->HousePhone, sizeof(this->HousePhone), HousePhone);

	if (strlen(MobilePhone) >= sizeof(this->MobilePhone))
		strcpy_s(this->MobilePhone, sizeof(this->MobilePhone), "No phone");
	else
		strcpy_s(this->MobilePhone, sizeof(this->MobilePhone), MobilePhone);

	if (strlen(WorkPhone) >= sizeof(this->WorkPhone))
		strcpy_s(this->WorkPhone, sizeof(this->WorkPhone), "No phone");
	else
		strcpy_s(this->WorkPhone, sizeof(this->WorkPhone), WorkPhone);
	
	this->infoAboutContact = new char[strlen(infoAboutContact) + 1];
	strcpy_s(this->infoAboutContact, strlen(infoAboutContact) + 1, infoAboutContact);

}
void Contact::show()
{
	cout << "Full name: " << FullName << endl;
	cout << "Home phone: " << HousePhone << endl;
	cout << "Mobile phone: " << MobilePhone << endl;
	cout << "Work phone: " << WorkPhone << endl;
	cout << "Info: " << infoAboutContact << endl;
}



Contact::~Contact()
{
	delete[] FullName;
	delete[] infoAboutContact;
}