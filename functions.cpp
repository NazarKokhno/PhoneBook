#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>  
#include <string.h> 
#include "Contact.h"
#include "constants.h"

using namespace std;

void SaveAll(Contact contacts[], int globalQuantity)
{
	FILE* f = fopen("contactsData.txt", "w");

	if (f == NULL)
	{
		perror("Error opening file");
		return;
	}

	for (int i = 0; i < globalQuantity; i++)
	{
		fprintf(f, "%s|%s|%s|%s|%s\n",
			contacts[i].getFullName(),
			contacts[i].getHousePhone(),
			contacts[i].getMobilePhone(),
			contacts[i].getWorkPhone(),
			contacts[i].getinfoAboutContact()
		);
	
	}
	
	fclose(f);

	cout << "Saved" << endl;
}
void AddContact(Contact contacts[], int ARR_SIZE, int& globalQuantity)
{
	int choice1;

	do
	{
		int i = globalQuantity;

		if (i >= ARR_SIZE)
		{
			cout << "Contact list is full!" << endl;
			break;
		}

		cout << "Enter full name: ";
		char name[100];
		cin.getline(name, 100);
		contacts[i].SetFullName(name);

		cout << "Enter home phone: ";
		char HP[PHONENUM_SIZE];
		cin.getline(HP, PHONENUM_SIZE);
		contacts[i].SetHousePhone(HP);

		cout << "Enter mobile phone: ";
		char MP[PHONENUM_SIZE];
		cin.getline(MP, PHONENUM_SIZE);
		contacts[i].SetMobilePhone(MP);

		cout << "Enter work phone: ";
		char WP[PHONENUM_SIZE];
		cin.getline(WP, PHONENUM_SIZE);
		contacts[i].SetWorkPhone(WP);

		cout << "Enter contact's info: ";
		char info[100];
		cin.getline(info, 100);
		contacts[i].SetinfoAboutContact(info);

		globalQuantity++;

		cout << "Contact added!" << endl;
		cout << "Save? (0 - No, 1 - Yes)" << endl;

		int choiceS;
		cout << "Your choice: ";
		cin >> choiceS;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');

		if (choiceS == 1)
		{
			SaveAll(contacts, globalQuantity);
		}

		cout << "Enter 0 to stop or 1 to add another contact: ";
		cin >> choice1;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');

	} while (choice1 != 0);
}
void SearchContact(Contact contacts[], int globalQuantity)
{
	char FullNameforSearch[100];

	int quantityFound = 0;

	cout << "Enter full name: ";
	cin.getline(FullNameforSearch, 100);

	for (int i = 0; i < globalQuantity; i++)
	{
		if (_stricmp(contacts[i].getFullName(), FullNameforSearch) == 0)
		{
			quantityFound++;
		}
	}
	
	cout << endl;
	cout << "Found: " << quantityFound << endl;
	
	for (int i = 0; i < globalQuantity; i++)
	{
		if (_stricmp(contacts[i].getFullName(), FullNameforSearch) == 0)
		{
			contacts[i].show();
			cout << endl;
		}
	}
	cout << endl;


}

void ShowAllContacts(Contact contacts[], int globalQuantity)
{
	cout << endl;

	for (int i = 0; i < globalQuantity; i++)
	{
		contacts[i].show();
		cout << endl;
	}

	cout << endl;
}



void ShowMenu()
{
	cout << "1 - Add new contact" << endl;
	cout << "2 - Delete contact" << endl;
	cout << "3 - Search by full name" << endl;
	cout << "4 - Show all local contacts" << endl;
	cout << "5 - Load from file" << endl;
	cout << "0 - Exit" << endl;
}

void menu(Contact contacts[], int ARR_SIZE, int& globalQuantity)
{
	int choice;
	while(true)
	{
		ShowMenu();

		cout << "Your choice: ";
		cin >> choice;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');


		switch (choice)
		{
		case 1:
		{
			AddContact(contacts, ARR_SIZE, globalQuantity);
			break;

		}

		case 2:
		{
			break;
		}

		case 3:
		{

			SearchContact(contacts, globalQuantity);
			break;
		}

		case 4:
		{
			ShowAllContacts(contacts, globalQuantity);
			break;
		}

		case 5:
		{
			break;
		}
		case 0:
		{
			cout << "Goodbye!" << endl;
			break;
		}

		default:
			cout << "Invalid choice!" << endl;
			break;

		}
	
		if (choice == 0)
			break;
	} 

}