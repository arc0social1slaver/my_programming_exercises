/**
 * File: ticket.cpp
 * ----------------
 * This program specifies all functions for asking for user’s age and calculating the zoo ticket cost based on the given age
 */
#include "ticket.h"

/**
 * Function: taskRunning()
 * Usage: taskRunning();
 * ---------------------
 * This function asks for user’s age and calculates the zoo ticket cost based on the given age. Note that if user types in the value less than 0
 * or greater than or equal to 100, this function will ask for user to type in again.
*/
void taskRunning()
{
    int age = -1;
    int choice = -1;
    while (true)
    {
        getInput(age, choice);
        if (choice == 0)
        {
            break;
        }
        if (age >= 0 || age < 100)
        {
            showOutput(age);
        }
    }
}
/**
 * Function: getInput(int &num, int &user)
 * Usage: getInput(age, choice);
 * --------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for the age. if user types in the value less than 0 or greater than 
 * or equal to 100, an error message will be printed on the screen.
 * @param num The age of user
 * @param user User's choice from the console
 */
void getInput(int &num, int &user)
{
    cout << "\t\t\t\tProgram calculating the zoo ticket cost based on the given age\n";
    cout << "\t\t\t\t--------------------------------------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user >= 1 && user <= 10)
    {
        cout << "Please type your age:\n";
        cin >> num;
        if (num < 0 || num >= 100)
        {
            cout << "Your age is out of range\n";
        }
    }
    else
    {
        user = 0;
        cout << "The program will terminate\n";
    }
}
/**
 * Function: showOutput(int num)
 * Usage: showOutput(age);
 * ----------------------------
 * This function displays the price of the ticket on the console
 * @param num The age of user 
*/
void showOutput(int num)
{
    if (num < 5)
    {
        cout << "The ticket is free\n";
    }
    else if (num >= 5 && num <= 10)
    {
        cout << "The ticket costs $10\n";
    }
    else if (num >= 11 && num <= 16)
    {
        cout << "The ticket costs $20\n";
    }
    else
    {
        cout << "The ticket costs $25\n";
    }
}