#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>  
#include <string.h> 
#include "functions.h"
#include "Contact.h"
#include "constants.h"


using namespace std;

int main()
{
    int globalQuantity = 5;

   

    Contact contacts[ARR_SIZE]
    {
        Contact("Nazar", "0536123456", "0671234567", "0536123456", "Friend"),
        Contact("Ivan", "0536111111", "0671111111", "0536111111", "Work"),
        Contact("Oleh", "0536222222", "0672222222", "0536222222", "Family"),
        Contact("Andriy", "0536333333", "0673333333", "0536333333", "Friend"),
        Contact("Petro", "0536444444", "0674444444", "0536444444", "Other")
    };
    
    menu(contacts, ARR_SIZE, globalQuantity);
    
    return 0;
	
}

