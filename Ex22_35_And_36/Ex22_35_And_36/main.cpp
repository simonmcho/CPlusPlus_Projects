//
//  main.cpp
//  Ex22_35_And_36
//  C String manipulations using functions from the <cstring> library
//
//  Created by simmons on 2017-11-10.
//  Copyright © 2017 simmonscho. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;
/*
 
// Allow user to input a telephone number, and output that in a sequential concatenated string,
// ignoring all characters other than the numbers 0 - 9.
int main(int argc, const char * argv[]) {
    char userPhoneNumber[80];
    char token[] = "()- ";
    char parsedPhoneNumber[10];
    
    cout << "Enter your phone number" << endl;
    
    cin.getline(userPhoneNumber, 80);
    
    char *tokenPtr =  strtok(userPhoneNumber, token);
    
    
    while ( tokenPtr != NULL)
    {
        strcat(parsedPhoneNumber, tokenPtr);
        tokenPtr = strtok(NULL, token);
    }
    
    cout << parsedPhoneNumber << endl;
    
    return 0;
}
 */


// Take a sentence input and tokenize the inputted text and outputs in reverse order
int main()
{
    cout << "Enter a sentence: \n" << endl;
    
    char sentence[80];
    char *pointers[20];
    unsigned int count = 0;
    char tokenSeparator[] = " ,.!?;:";
    
    cin.getline(sentence, 80);
    
    char *tokenPtr = strtok(sentence, tokenSeparator);
    
    while(tokenPtr != NULL)
    {
        pointers[count++] = tokenPtr;
        tokenPtr = strtok(NULL, tokenSeparator);
    }
    
    count--;
    
    for(int i = count; i >= 0; i--)
    {
        cout << pointers[i] << ' ';
    }
    cout << endl;
    //system("pause"); //xcode "pause" cmd not found
}
