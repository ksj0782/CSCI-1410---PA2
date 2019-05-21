//
// Created by Henok on 3/5/2019.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

using namespace std;

//Proto type of struct "Magic8Response"
struct Magic8Response
{
    string answer;
    string category;
}; //struct 'Magic8Response' has two components: 'answer and 'category'.

//Requirement A
int ReadResponses(ifstream &infile, Magic8Response responses[], const int &max_size, int& size); // Prototype of function for menu 'a'.

//B
void PlayMagic8(Magic8Response responses[], int&  size); // Prototype of function for menu 'b'.

//C
void PrintResponsesAndCategories(Magic8Response responses[], int& size); // Prototype of function for menu 'c'.

//D
void WriteResponsesToFile(Magic8Response responses[], int& size); //Prototype of function for menu 'd'.

//Extra credit
void DeleteResponse(Magic8Response responses[], int& size); // Prototype of function for menu 'f'.

void menuOption(); // Prototype of menu option.

#endif //FUNCTIONS_H