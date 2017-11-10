//
//  main.cpp
//  Ex22_35_And_36
//  C String manipulations using functions from the <cstring> library
//  22.35: Allow user to input a telephone number, and output that in a sequential concatenated string,
//         ignoring all characters other than the numbers 0 - 9.
//
//  Created by simmons on 2017-11-10.
//  Copyright © 2017 simmonscho. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    char userPhoneNumber[80];
    
    cout << "Enter your phone number" << endl;
    
    cin.getline(userPhoneNumber, 80);
    
    cout << strtok(userPhoneNumber, "-") << endl;
    
    return 0;
}
