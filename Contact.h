#pragma once
#include "constants.h"
class Contact
{
private:
	char* FullName;
	char HousePhone[PHONENUM_SIZE];
	char MobilePhone[PHONENUM_SIZE];
	char WorkPhone[PHONENUM_SIZE];
	char* infoAboutContact;
public:
	Contact();
	Contact(const char* FullName, const char* HousePhone, const char* MobilePhone, const char* WorkPhone, const char* infoAboutContact);
	Contact(const char* FullName);

	void CopyFrom(const Contact& other);
	void show();
	
	const char* getFullName() const;
	const char* getHousePhone() const;
	const char* getMobilePhone() const;
	const char* getWorkPhone() const;
	const char* getinfoAboutContact() const;

	void SetFullName(const char* name);
	void SetHousePhone(const char* housePhone);
	void SetMobilePhone(const char* mobilePhone);
	void SetWorkPhone(const char* workPhone);
	void SetinfoAboutContact(const char* info);

	~Contact();

};