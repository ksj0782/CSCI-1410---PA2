//
// Created by Sungjoon Kim on 3/28/2019.
//
#include <iostream>
#include <string>
#include <fstream>
#include "functions.h"

using namespace std;

//A
int ReadResponses(ifstream &infile, Magic8Response responses[], const int &max_size, int& size)
{
    size = max_size;

    char menu;


    // Get the answers and categories from the input file.
    // There are total 20 answers and categories, so execute the for loop 20 times.
    for (int i = 0; i < max_size; i++)
    {
        getline(infile, responses[i].answer);
        getline(infile, responses[i].category);
    }


    cout << "\nRead completely!" << endl;
    cout << "Choose another option!\n" << endl;


    // While menu is equal to 'a' or 'A', get another option because the answers are already read.
    while (menu == 'a' || menu == 'A')
    {
        cout << "\nAlready read responses" << endl
             << "Choose other options" << endl;
        cin >> menu;
    }


    return max_size;
}


//B
void PlayMagic8(Magic8Response responses[], int& size)
{
    bool choose = true; // Boolean function for the while loop.

    while (choose)
    {

        string question;

        cout << "\nPlease ask me a question. I will tell you the future!" << endl;

        cout << "Q: ";

        cin.ignore();
        getline(cin, question); // Get a question from console.

        int randomNumber = rand() % size; // Define 'randomNumber' variable which is going to be index number.

        cout << "A: " << responses[randomNumber].answer << endl << responses[randomNumber].category << endl; // Among 20 answers, print a random answer.

        // Copy the random answer and category of the answer to the new arrays.
        // This new arrays will be printed on the menu 'c'
        // This new arrays will be also written in the output file on the menu 'd'.

        cout << "Another question? (Y/N)" << endl;

        char choice;

        cin >> choice;

        switch (choice)
        {
            case 'y':
            case 'Y':
                break;
                // If 'choice' is 'y' or 'Y', go back to the while loop again since 'choose' is still true.

            case 'n':
            case 'N':
                choose = false;
                // If 'choice' is 'n' or 'N', 'choose' changes to false, and excape the while loop.
        }

    }

}


//C
void PrintResponsesAndCategories(Magic8Response responses[], int& size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (responses[i].answer > responses[j].answer)
            {
                string temp1 = responses[i].answer;
                responses[i].answer = responses[j].answer;
                responses[j].answer = temp1;

                string temp2 = responses[i].category;
                responses[i].category = responses[j].category;
                responses[j].category = temp2;
                // Sort the arrays in alphabetical order by using for loops.
                // If the first letter of an answer has greater integer value than another answer, then the answer that has greater integer value goes back.
                // 'b' has greater integer value than 'a', so 'a' comes first, and 'b' comes next.
            }
        }

    }


    for (int i = 0; i < size; i++)
    {
        cout << responses[i].answer << endl << responses[i].category << endl;
    }
    // Print out all the answers and categories of them
}


//D
void WriteResponsesToFile(Magic8Response responses[], int& size)
{
    ofstream outfile;
    outfile.open("Write.txt");

    for(int i = 0; i < size; i++)
    {
        outfile << responses[i].answer << endl << responses[i].category << endl;
    }
    // ofstream function to write the answers and categories to the output file.
    // Write all the answers and categories of them, by using for loop.

    outfile.close();

    cout << "Completely wrote the answers into file\n" << endl;
}


//Extra credit
void DeleteResponse(Magic8Response responses[], int& size)
{
    cout << "Which kind of answers do you want to delete? 1) Positive 2) Negative 3) Vague 4) All 5) Specific lind: ";

    int tempNum = size;

    bool Del = false; // for while loop

    int DelAns; // number option

    int counter = 0;

    cin >> DelAns;

    while(!Del)
    {
        switch (DelAns)
        {
            case 1: // option 1) positive
            {
                for (int i = 0; i < tempNum; i++)
                {
                    while(responses[i].category == "positive") // if category is positive
                        {
                            responses[i].answer = "";
                            responses[i].category = "";
                            // remove the elements corresponding to positive category

                            counter++;

                            size--;

                            for(int j = i;j < tempNum-1;j++)
                            {
                                responses[j].answer = responses[j+1].answer;
                                responses[j].category = responses[j+1].category;
                            }

                            responses[tempNum - counter].answer = "";
                            responses[tempNum - counter].category = "";

                        }
                }
            }
            cout << "Completely Deleted!" << endl;
            Del = true;
            break;

            case 2: // option 2) negative
            {
                for (int i = 0; i < tempNum; i++)
                {
                    while(responses[i].category == "negative") // if category is positive
                    {
                        responses[i].answer = "";
                        responses[i].category = "";
                        // remove the elements corresponding to positive category

                        counter++;

                        size--;

                        for(int j = i;j < tempNum-1;j++)
                        {
                            responses[j].answer = responses[j+1].answer;
                            responses[j].category = responses[j+1].category;
                        }

                        responses[tempNum - counter].answer = "";
                        responses[tempNum - counter].category = "";

                    }
                }


            }
            cout << "Completely Deleted!" << endl;
            Del = true;
            break;

            case 3: // option 3) vague
            {
                for (int i = 0; i < tempNum; i++)
                {
                    while(responses[i].category == "vague") // if category is positive
                    {
                        responses[i].answer = "";
                        responses[i].category = "";
                        // remove the elements corresponding to positive category

                        counter++;

                        size--;

                        for(int j = i;j < tempNum-1;j++)
                        {
                            responses[j].answer = responses[j+1].answer;
                            responses[j].category = responses[j+1].category;
                        }

                        responses[tempNum - counter].answer = "";
                        responses[tempNum - counter].category = "";
                    }
                }
            }
            cout << "Completely Deleted!" << endl;
            Del = true;
            break;

            case 4: // option 4) all
            {
                for (int i = 0; i < tempNum; i++)
                {
                    responses[i].answer = "";
                    responses[i].category = "";
                    // remove all elements
                }
                size = 0;
            }
            cout << "Completely Deleted!" << endl;
            Del = true;
            break;

            case 5: // option 5) which line?
            {
                int LineNum;

                cout << "Which lind do you want to delete?";

                cin >> LineNum;

                responses[LineNum-1].answer = "";
                responses[LineNum-1].category = "";
                // remove specific line

                counter++;

                for(int j = LineNum-1;j < tempNum-1;j++)
                {
                    responses[j].answer = responses[j+1].answer;
                    responses[j].category = responses[j+1].category;
                }

                responses[tempNum - counter].answer = "";
                responses[tempNum - counter].category = "";

                size--;

            }
            cout << "Completely Deleted!" << endl;
            Del = true;
            break;

            default:
            {
                cout << "Wrong Category.\n" << endl;
            }
            break;
        }
    }


}


// 'menuOption' function which is used for printing menu options.
void menuOption()
{
    cout << "Welcome to Magic Eight Ball Game!" << endl;

    cout << "a. Read response from a file." << endl
         << "b. Play Magic Eight Ball." << endl
         << "c. Print out responses and categories alphabetically." << endl
         << "d. Write responses to a file." << endl
         << "e. Exit." << endl
         << "f. Delete answers" << endl;
    cout << "Choose a menu: ";
}
