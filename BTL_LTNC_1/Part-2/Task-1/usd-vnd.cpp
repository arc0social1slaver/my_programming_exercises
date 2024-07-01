/**
 * File: usd-vnd.cpp
 * ---------------
 * This program specifies all function needed for getting the value of USD from user and displaying the value of USD and VND to the console
 */
#include "usd-vnd.h"

/**
 * Function: taskRunning().
 * Usage: taskRunning();
 * ------------------------
 * This function gets the value of USD from user, converts USD into VND and displays both USD and VND. Moreover, if USD is less than 0, the
 * function will ask the user to input USD again.
 */
void taskRunning()
{
    double usdVal = 0;
    double vndVal = 0;
    int choice = -1;
    while (true)
    {
        getInput(usdVal, choice);
        if (choice == 0)
        {
            break;
        }
        if (usdVal >= 0)
        {
            vndVal = usdToVnd(usdVal);
            showOutput(usdVal, vndVal);
        }
    }
}
/**
 * Function: getInput(double &num, int &user)
 * Usage: getInput(usdVal, choice);
 * --------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for the value of USD. If USD's value is less than 0, an error message will be
 * printed on the screen
 * @param num The USD's value of the user
 * @param user User's choice from the console
 */
void getInput(double &num, int &user)
{
    cout << "\t\t\t\tProgram converting USD to VND\n";
    cout << "\t\t\t\t-----------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user >= 1 && user <= 10)
    {
        cout << "Please type the value of USD (Note that your number should not less than 0):\n";
        cin >> num;
        if (num < 0)
        {
            cout << "Your USD value is invalid\n";
        }
    }
    else
    {
        user = 0;
        cout << "The program will terminate\n";
    }
}
/**
 * Function: usdToVnd(double num).
 * Usage: vndVal = usdToVnd(usdVal);
 * --------------------------------
 * This function convert USD to VND.
 * @param num The USD's value
 * @return The VND's value
 */
double usdToVnd(double num)
{
    return num * VND_PER_USD;
}
/**
 * Function: showOutput(double num1, double num2).
 * Usage: showOutput(usdVal, vndVal);
 * ---------------------------------------------
 * This function shows the information in a table format. Every row is seperated by the line containing '-'. Moreover, we can use this function
 * to shows the title of each column in the table
 * @param num1 The USD's value
 * @param num2 The VND's value
*/
void showOutput(double num1, double num2)
{
    cout << setw(20) << left << "USD";
    cout << setw(20) << left << "VND" << endl;

    cout << setfill('-');
    cout << setw(40) << "-" << endl;
    cout << setfill(' ');

    cout << setw(20) << left << num1;
    cout << setw(20) << left << num2 << endl;

    cout << setfill('-');
    cout << setw(40) << "-" << endl;
    cout << setfill(' ');
}