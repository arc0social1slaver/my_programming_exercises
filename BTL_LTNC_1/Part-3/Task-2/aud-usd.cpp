/**
 * File: aud-usd.cpp
 * -----------------
 * This program specifies all functions for asking for user input for the amount of money in VND and displaying the converted concurrency
 * on the console based on the user's choice
 */
#include "aud-usd.h"

/**
 * Function: taskRunning()
 * Usage: taskRunning();
 * ---------------------
 * This function asks for user input for the amount of money in VND and displays the converted concurrency on the console based on 
 * the user's choice.
*/
void taskRunning()
{
    double vnd = 0;
    double result = 0;
    int choice = -1;
    int audOrUsd = -1;
    while (true)
    {
        getInput(vnd, result, audOrUsd, choice);
        if (choice == 0 || (audOrUsd != 1 && audOrUsd !=2))
        {
            break;
        }
        if (vnd >= 0)
        {
            showOutput(vnd, result, audOrUsd);
        }
    }
}
/**
 * Function: getInput(double &vnd, double &res, int &choice, int &user)
 * Usage: getInput(vnd, result, audOrUsd, choice);
 * -------------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for the value of VND. If VND's value is less than 0, an error message will be
 * printed on the screen. Then, this function prompts the user to choose their currency: AUD or USD. If user's choice is invalid, the
 * program will terminate.
 * @param vnd The VND's user
 * @param res The value after converting
 * @param choice The user choice between AUD or USD
 * @param user User's choice on starting or terminating the program from the console 
*/
void getInput(double &vnd, double &res, int &choice, int &user)
{
    cout << "\t\t\t\tProgram converting VND to AUD or USD\n";
    cout << "\t\t\t\t------------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user >= 1 && user <= 10)
    {
        cout << "Please type the value of VND (Note that your number should not less than 0):\n";
        cin >> vnd;
        if (vnd < 0)
        {
            cout << "Your VND value is invalid\n";
        }
        else
        {
            cout << "Please make a choice on choosing the currency by typing an integer based on the following:\n";
            cout << "1. Converting to AUD\n";
            cout << "2. Converting to USD\n";
            cout << "Otherwise, the program will terminate\n";
            cout << "Please type a number: ";
            cin >> choice;
            if (choice == 1 || choice == 2)
            {
                res = converter(vnd, choice);
            }
            else
            {
                cout << "The program will terminate\n";
            }
        }
    }
    else
    {
        user = 0;
        cout << "The program will terminate\n";
    }
}
/**
 * Function: converter(double vnd, int choice)
 * Usage: converResult = converter(vnd, choice);
 * --------------------------------------------
 * This function converts VND into the currency of the user
 * @param vnd The VND value
 * @param choice The user choice between AUD or USD
 * @return The converted currency
*/
double converter(double vnd, int choice)
{
    switch (choice)
    {
    case AUD:
        return vnd * VND_PER_AUD;
    case USD:
        return vnd * VND_PER_USD;
    default:
        break;
    }
    return 0;
}
/**
 * Function: showOutput(double vnd, double res, int choice)
 * Usage: showOutput(vnd, result, audOrUsd);
 * -------------------------------------------------------
 * This function shows the result to the console.
 * @param vnd The VND value
 * @param res The value after converting
 * @param choice The user choice between AUD or USD
*/
void showOutput(double vnd, double res, int choice)
{
    switch (choice)
    {
    case AUD:
        cout << "The value of " << vnd << " when converting to AUD is: " << res << endl;
        break;
    case USD:
        cout << "The value of " << vnd << " when converting to USD is: " << res << endl;
        break;
    default:
        break;
    }
}