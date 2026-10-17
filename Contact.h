#pragma once
class Contact
{
private:
	char* FullName;
	char HousePhone[17];
	char MobilePhone[17];
	char WorkPhone[17];
	char* infoAboutContact;
public:
	Contact();
	Contact(const char* FullName, const char* HousePhone, const char* MobilePhone, const char* WorkPhone, const char* infoAboutContact);
	Contact(const char* FullName);
	void show();
	
	const char* getFullName() const
	{
		return FullName;
	}

	~Contact();

};