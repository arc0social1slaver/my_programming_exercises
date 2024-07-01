/**
 * File: guess.cpp
 * --------------
 * This program specifies all functions needed for guessing the secret number
 */
#include "guess.h"

void taskRunning()
{
    int choice = -1;
    while (true)
    {
        getInput(choice);
        if (choice == 0)
        {
            break;
        }
        guessProc(choice);
        if (choice == 0)
        {
            break;
        }
    }
}
void getInput(int &user)
{
    cout << "\t\t\t\tProgram guessing the secret number\n";
    cout << "\t\t\t\t----------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user < 1 || user > 10)
    {
        user = 0;
        cout << "The program will terminate\n";
    }
}
void guessProc(int &user)
{
    int numUser = -1;
    while (true)
    {
        cout << "Please guess our number (Note that if your number is less than 0 or greater than 20, the program will terminate):\n";
        cin >> numUser;
        if (numUser < 0 || numUser > 20)
        {
            cout << "Your number is out of range. The program will terminate\n";
            user = 0;
            break;
        }
        if (numUser == SECRET_NUM)
        {
            cout << "You guessed our number. Congratulations\n";
            break;
        }
        else if (numUser < SECRET_NUM)
        {
            cout << "Our secret number is greater than your number. Try again!\n";
        }
        else
        {
            cout << "Our secret number is smaller than your number. Try again!\n";
        }
    }
}