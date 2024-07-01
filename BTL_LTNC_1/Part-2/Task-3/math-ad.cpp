/**
 * File: math-ad.cpp
 * -----------------
 * This program specifies all function needed for taking one number from the user then calculating and displaying its abs, sin, cos,
 * tan, log, log10, sqrt, exp
 */
#include "math-ad.h"

/**
 * Function: taskRunning()
 * Usage: taskRunning()
 * ----------------------
 * This function takes one number from the user then calculates and displays its abs, sin, cos, tan, log, log10, sqrt, exp
*/
void taskRunning()
{
    double numUser = 0;
    double result = 0;
    int choice = -1;
    while (true)
    {
        getInput(numUser, choice);
        if (choice == 0)
        {
            break;
        }
        showOutput(numUser, result);
    }
}
/**
 * Function: getInput(double &num, int &user).
 * Usage: getInput(numUser, choice);
 * --------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for a number
 * @param num The number of the user
 * @param user User's choice from the console
 */
void getInput(double &num, int &user)
{
    cout << "\t\t\t\tProgram calcuting the abs, sin, cos, tan, log, log10, sqrt, exp of the number from user\n";
    cout << "\t\t\t\t---------------------------------------------------------------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user >= 1 && user <= 10)
    {
        cout << "Please type your number:\n";
        cin >> num;
    }
    else
    {
        user = 0;
        cout << "The program will terminate\n";
    }
}
/**
 * Function: showOutput(double num, double &res).
 * Usage: showOutput(numUser, result);
 * --------------------------------------------------------------
 * This function shows to the console the number typed by the user and calculating the abs, sin, cos, tan, log, log10, sqrt, exp 
 * of the number respectively.
 * @param num The number of the user
 * @param res The result after evaluating abs, sin, cos, tan, log, log10, sqrt, exp
*/
void showOutput(double num, double &res)
{
    for (int i = 0; i < 8; i++)
    {
        mathBasedOnChoice(num, res, i);
        showBasedOnChoice(num, res, i);
    }
}
/**
 * Function: mathBasedOnChoice(double num, double &res, int choice)
 * Usage: mathBasedOnChoice(num, result, choice);
 * ----------------------------------------------------------------
 * This function calculates the abs, sin, cos, tan, log, log10, sqrt, exp  of the numbers respective (because the choice goes from
 * 0 to 7)
 * @param num The number of the user
 * @param res The result after evaluating abs, sin, cos, tan, log, log10, sqrt, exp
 * @param choice The choice in order to decide which math function needed to use
*/
void mathBasedOnChoice(double num, double &res, int choice)
{
    switch (choice)
    {
    case ABS:
        res = abs(num);
        break;
    case SIN:
        res = sin(num);
        break;
    case COS:
        res = cos(num);
        break;
    case TAN:
        res = tan(num);
        break;
    case LOG:
        if (num > 0)
        {
            res = log(num);
        }
        break;
    case LOG10:
        if (num > 0)
        {
            res = log10(num);
        }
        break;
    case SQRT:
        if (num > 0)
        {
            res = sqrt(num);
        }
        break;
    case EXP:
        res = exp(num);
        break;
    }
}
/**
 * Function: showBasedOnChoice(double num, double res, int choice)
 * Usage: showBasedOnChoice(num, result, choice);
 * --------------------------------------------------------------
 * This function shows the result of each math function to the console
 * @param num The number of the user
 * @param res The result after evaluating abs, sin, cos, tan, log, log10, sqrt, exp
 * @param choice The choice in order to decide which math function needed to show
*/
void showBasedOnChoice(double num, double res, int choice)
{
    switch (choice)
    {
    case ABS:
        cout << "The abs of " << num << " is: " << res << endl;
        break;
    case SIN:
        cout << "The sin of " << num << " is: " << res << endl;
        break;
    case COS:
        cout << "The cos of " << num << " is: " << res << endl;
        break;
    case TAN:
        cout << "The tan of " << num << " is: " << res << endl;
        break;
    case LOG:
        if (num > 0)
        {
            cout << "The log of " << num << " is: " << res << endl;
        }
        else
        {
            cout << "Since " << num << " is less than or equals to zero, the log of " << num << " cannot be evaluated" << endl;
        }
        break;
    case LOG10:
        if (num > 0)
        {
            cout << "The log10 of " << num << " is: " << res << endl;
        }
        else
        {
            cout << "Since " << num << " is less than or equals to zero, the log10 of " << num << " cannot be evaluated" << endl;
        }
        break;
    case SQRT:
        if (num > 0)
        {
            cout << "The sqrt of " << num << " is: " << res << endl;
        }
        else
        {
            cout << "Since " << num << " is less than or equals to zero, the sqrt of " << num << " cannot be evaluated" << endl;
        }
        break;
    case EXP:
        cout << "The exp of " << num << " is: " << res << endl;
        break;
    }
}