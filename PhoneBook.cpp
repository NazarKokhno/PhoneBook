#include <iostream>
#include <windows.h>
#include "Contact.h"
#include "functions.h"

using namespace std;

int main()
{
    const int ARR_SIZE = 100;

    Contact contacts[100]
    {
        Contact("Nazar", "0536123456", "0671234567", "0536123456", "Friend"),
        Contact("Ivan", "0536111111", "0671111111", "0536111111", "Work"),
        Contact("Oleh", "0536222222", "0672222222", "0536222222", "Family"),
        Contact("Andriy", "0536333333", "0673333333", "0536333333", "Friend"),
        Contact("Petro", "0536444444", "0674444444", "0536444444", "Other")
    };
    
    ShowMenu();
    
    return 0;
	
}

