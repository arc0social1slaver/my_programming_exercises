/**
 * File: percentage.cpp
 * --------------------
 * This program specifies all functions needed for calculating and displaying x percentage of a number y
 */
#include "percentage.h"

/**
 * Function: taskRunning().
 * Usage: taskRunning();
 * ------------------------
 * This function gets x and y from user, calculates and displays x percentage of a number y. Moreover, if x or y is less than 0, the fucntion will
 * ask the user to input x and y again.
*/
void taskRunning()
{
    double firstNum = 0;
    double secondNum = 0;
    double result = 0;
    int choice = -1;
    while (true)
    {
        getInput(firstNum, secondNum, choice);
        if (choice == 0)
        {
            break;
        }
        if (firstNum >= 0 && secondNum >= 0)
        {
            result = percentOf(firstNum, secondNum);
            showOutput(firstNum, secondNum, result);
        }
    }
}
/**
 * Function: getInput(double &num1, double &num2, int &user)
 * Usage: getInput(firstNum, secondNum, choice);
 * --------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for two number x and y. If x or y is less than 0, an error message will be
 * printed on the screen
 * @param num1 First number from the user (which is x)
 * @param num2 Second number from the user (which is y)
 * @param user User's choice from the console
 */
void getInput(double &num1, double &num2, int &user)
{
    cout << "\t\t\t\tProgram calcuting x percentage of a number y\n";
    cout << "\t\t\t\t--------------------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user >= 1 && user <= 10)
    {
        cout << "Please type the percentage x that you want to calculate (Note that your number should not less than 0):\n";
        cin >> num1;
        if (num1 < 0)
        {
            cout << "Your percentage number x is invalid\n";
        }
        else
        {
            cout << "Please type your number y (Note that your number should not less than 0):\n";
            cin >> num2;

            if (num2 < 0)
            {
                cout << "Your number y is invalid\n";
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
 * Function: showOutput(double num1, double num2, double result).
 * Usage: showOutput(firstNum, secondNum, result);
 * -------------------------------------------------------------
 * This function shows the x percentage of y to the console
 * @param num1 First number from the user (which is x)
 * @param num2 Second number from the user (which is y)
 * @param result The x percentage of y
*/
void showOutput(double num1, double num2, double result)
{
    cout << "The " << num1 << "% of " << num2 << " is: " << result << endl;
}
/**
 * Function: percentOf(double num1, double num2)
 * Usage: result = percentOf(firstNum, secondNum);
 * -----------------------------------------------
 * This function calculates x percentage of y
 * @param num1 First number from the user (which is x)
 * @param num2 Second number from the user (which is y)
 * @return The x percentage of y
*/
double percentOf(double num1, double num2)
{
    return num1 * num2 / 100;
}