//
// Created by Sungjoon Kim on 3/28/2019.
//

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "functions.h"

using namespace std;

int main()
{

    srand(time(0));

    char menu;

    const int max_size = 20;

    int currentSize = 20;

    struct Magic8Response responses[max_size]; // Define the name of struct and the number of elements of two string arrays of the struct.

    ifstream infile; // ifstream functions to read input file.

    bool done = false;

    while(!done)
    {
        menuOption(); // Menu Options.

        cin >> menu;

        switch (menu) // Switch statement for variable 'menu'.
        {
            case 'a':
            case 'A':
            {
                if ((responses->answer.empty()) || (responses->category.empty()))
                {
                    infile.open("responses.txt"); // Open the input file.
                    ReadResponses(infile, responses, max_size, currentSize); // If 'menu' is equal to 'a' or 'A', then execute the function 'ReadResponses'.
                    infile.close();
                }
            }
                break;

            case 'b':
            case 'B':
                PlayMagic8(responses, currentSize); // If 'menu' is equal to 'b' or 'B', then execute the function 'PlayMagic8'.
                break;


            case 'c':
            case 'C':
                PrintResponsesAndCategories(responses, currentSize);
                break;
                // If 'menu' is equal to 'c' or 'C', then execute the function 'PrintResponsesAndCategories'.

            case 'd':
            case 'D':
                WriteResponsesToFile (responses, currentSize);
                break;
                // If 'menu' is equal to 'd' or 'D', then execute the function 'WriteResponsesToFile'.

            case 'e':
            case 'E':
                done = true;
                break;
                // If 'menu' is equal to 'e' or 'E', then end the program.

            case 'f':
            case 'F':
                DeleteResponse(responses, currentSize);
                break;
                // If 'menu' is equal to 'f' or 'F', then execute the function 'DeleteResponse'


            default:
            {
                cout << "Wrong Option.\n" << endl;
                break;
            }

                // If 'menu' is not equal to any of those, then go back to the menu.
        }
    }

    return 0;
}


