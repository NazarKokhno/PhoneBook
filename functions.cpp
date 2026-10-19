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

		cout << "\nContact added!" << endl;
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
void DeleteContact(Contact contacts[], int& globalQuantity)
{
	char FullNameforSearch[100];

	int count = 0;

	cout << "Enter full name: ";
	cin.getline(FullNameforSearch, 100);

	for (int i = 0; i < globalQuantity; i++)
	{
		if (_stricmp(contacts[i].getFullName(), FullNameforSearch) == 0)
		{
			count++;
		}
	}

	if (count == 0)
	{
		cout << "Contact not found." << endl;
		return;
	}


	int* indexes = new int[count];

	int j = 0;

	for (int i = 0; i < globalQuantity; i++)
	{
		if (_stricmp(contacts[i].getFullName(), FullNameforSearch) == 0)
		{
			indexes[j] = i;
			j++;
		}
	}

	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << ". ";
		contacts[indexes[i]].show();
		cout << endl;
	}

	int choice;
	cout << "Enter contact number to delete: ";
	cin >> choice;
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');

	if (choice < 1 || choice > count)
	{
		cout << "Invalid choice!" << endl;
		delete[] indexes;
		return;
	}

	int contactIndex = indexes[choice - 1];

	for (int i = contactIndex; i < globalQuantity - 1; i++)
	{
		contacts[i].CopyFrom(contacts[i + 1]);
	}

	globalQuantity--;

	delete[] indexes;

	cout << "\nContact deleted!" << endl;
	SaveAll(contacts, globalQuantity);

}
void ShowAllContacts(Contact contacts[], int globalQuantity)
{
	cout << endl;

	for (int i = 0; i < globalQuantity; i++)
	{
		contacts[i].show();
		cout << endl;
	}

	cout << "It`s all!" << endl;

	cout << endl;
}
bool LoadContactFromFile(Contact contacts[], int ARR_SIZE,int& globalQuantity, bool quikCheck)
{
	if (quikCheck)
	{
		cout << "Already synchronized" << endl;
		return false;
	}

	FILE* f = fopen("contactsData.txt", "r");

	if (f == NULL)
	{
		perror("Error opening file");
		return false;
	}

	char line[500];

	while (fgets(line, sizeof(line), f) != NULL)
	{
		if (globalQuantity >= ARR_SIZE)
		{
			cout << "Contact list is full!" << endl;
			break;
		}

		char* name = strtok(line, "|");
		char* HP = strtok(NULL, "|");
		char* MP = strtok(NULL, "|");
		char* WP = strtok(NULL, "|");
		char* info = strtok(NULL, "\r\n");

		if (name == NULL || HP == NULL || MP == NULL ||
			WP == NULL || info == NULL)
		{
			continue;
		}

		contacts[globalQuantity].SetFullName(name);
		contacts[globalQuantity].SetHousePhone(HP);
		contacts[globalQuantity].SetMobilePhone(MP);
		contacts[globalQuantity].SetWorkPhone(WP);
		contacts[globalQuantity].SetinfoAboutContact(info);

		globalQuantity++;
	}
	
	fclose(f);
	cout << "Contacts loaded" << endl;
	return true;

}

void ShowMenu()
{
	cout << "\n1 - Add new contact" << endl;
	cout << "2 - Delete contact" << endl;
	cout << "3 - Search by full name" << endl;
	cout << "4 - Show all local contacts" << endl;
	cout << "5 - Load from file" << endl;
	cout << "0 - Exit" << endl;
}

void menu(Contact contacts[], int ARR_SIZE, int& globalQuantity)
{
	
	bool quickCheck = false;

	if (globalQuantity == 0)
	{
		int choice;
		cout << "There are no contacts in your new profile yet. Would you like to sync local accounts with the app?" << endl;
		cout << "0 - No, 1 - Yes" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');

		switch (choice)
		{
		case 1:
			quickCheck = LoadContactFromFile(
				contacts, ARR_SIZE, globalQuantity, quickCheck);
			break;
		
		case 0:
			break;
		
		default:
			cout << "Invalid input!" << endl;
			break;

		}
	}
	
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
			DeleteContact(contacts, globalQuantity);
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

			quickCheck = LoadContactFromFile(
				contacts, ARR_SIZE, globalQuantity, quickCheck);
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