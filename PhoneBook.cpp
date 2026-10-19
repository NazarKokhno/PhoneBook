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
    int globalQuantity = 0;

    Contact contacts[ARR_SIZE];
    
    menu(contacts, ARR_SIZE, globalQuantity);
    
    return 0;
	
}

