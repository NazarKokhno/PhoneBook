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

const char* Contact::getFullName() const
{
	return FullName;
}

const char* Contact::getHousePhone() const
{
	return HousePhone;
}

const char* Contact::getMobilePhone() const
{
	return MobilePhone;
}

const char* Contact::getWorkPhone() const
{
	return WorkPhone;
}

const char* Contact::getinfoAboutContact() const
{
	return infoAboutContact;
}

void Contact::SetFullName(const char* name)
{
	char* newName = new char[strlen(name) + 1];
	strcpy_s(newName, strlen(name) + 1, name);

	delete[] FullName;
	FullName = newName;
}

void Contact::SetHousePhone(const char* housePhone)
{
	if (strlen(housePhone) >= PHONENUM_SIZE)
	{
		strcpy_s(HousePhone, PHONENUM_SIZE, "No phone");
		return;
	}

	strcpy_s(HousePhone, PHONENUM_SIZE, housePhone);
}

void Contact::SetMobilePhone(const char* mobilePhone)
{
	if (strlen(mobilePhone) >= PHONENUM_SIZE)
	{
		strcpy_s(MobilePhone, PHONENUM_SIZE, "No phone");
		return;
	}

	strcpy_s(MobilePhone, PHONENUM_SIZE, mobilePhone);
}

void Contact::SetWorkPhone(const char* workPhone)
{
	if (strlen(workPhone) >= PHONENUM_SIZE)
	{
		strcpy_s(WorkPhone, PHONENUM_SIZE, "No phone");
		return;
	}

	strcpy_s(WorkPhone, PHONENUM_SIZE, workPhone);
}

void Contact::SetinfoAboutContact(const char* info)
{
	char* newInfo = new char[strlen(info) + 1];
	strcpy_s(newInfo, strlen(info) + 1, info);

	delete[] infoAboutContact;
	infoAboutContact = newInfo;
}

void Contact::show()
{
	cout << FullName << "|" << HousePhone << "|" << MobilePhone << "|" << WorkPhone << "|" << infoAboutContact;
}

void Contact::CopyFrom(const Contact& other)
{
	SetFullName(other.getFullName());
	SetHousePhone(other.getHousePhone());
	SetMobilePhone(other.getMobilePhone());
	SetWorkPhone(other.getWorkPhone());
	SetinfoAboutContact(other.getinfoAboutContact());
}

Contact::~Contact()
{
	delete[] FullName;
	delete[] infoAboutContact;
}