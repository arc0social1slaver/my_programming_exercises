/**
 * File: average.cpp
 * -----------------
 * This program specifies all function needed for getting input/output and calculating average of three integer number
 */
#include "average.h"

/**
 * Function: taskRunning
 * Usage: taskRunning();
 * ---------------------
 * This function gets three integer numbers from the console and show the result to the console
 */
void taskRunning()
{
    int choice = -1;
    int firstNum = -1;
    int secondNum = -1;
    int thirdNum = -1;
    double result = 0;
    while (true)
    {
        getInput(firstNum, secondNum, thirdNum, choice);
        if (choice == 0)
        {
            break;
        }
        result = calcAvg(firstNum, secondNum, thirdNum);
        showOutput(firstNum, secondNum, thirdNum, result);
    }
}

/**
 * Function: getInput(int &num1, int &num2, int &num3, int &user)
 * Usage: getInput(firstNum, secondNum, thirdNum, choice);
 * --------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for three integer numbers
 * @param num1 First number from the user
 * @param num2 Second number from the user
 * @param num3 Third number from the user
 * @param user User's choice from the console
 */
void getInput(int &num1, int &num2, int &num3, int &user)
{
    cout << "\t\t\t\tProgram calcuting the average of three integer numbers\n";
    cout << "\t\t\t\t------------------------------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user >= 1 && user <= 10)
    {
        cout << "Please type your first number:\n";
        cin >> num1;
        cout << "Please type your second number:\n";
        cin >> num2;
        cout << "Please type your third number:\n";
        cin >> num3;
    }
    else
    {
        user = 0;
        cout << "The program will terminate\n";
    }
}
/**
 * Function: calcAvg(int num1, int num2, int num3)
 * Usage: avgResult = calcAvg(num1, num2, num3)
 * -----------------------------------------------
 * This function takes three integer numbers and return the average of them
 * @param num1 First integer number of the user
 * @param num2 Second integer number of the user
 * @param num3 Third integer number of the user
 * @return The average of three numbers
 */
double calcAvg(int num1, int num2, int num3)
{
    return ((double)num1 + num2 + num3) / 3;
}
/**
 * Function: showOutput(int num1, int num2, int num3, double res)
 * Usage: showOutput(num1, num2, num3, avgResult);
 * --------------------------------------------------------------
 * This function shows to the console three numbers typed by the user and the avegrage of these numbers
 * @param num1 First integer number of the user
 * @param num2 Second integer number of the user
 * @param num3 Third integer number of the user
 * @param res The average of three numbers
*/
void showOutput(int num1, int num2, int num3, double res)
{
    cout << "The average of three numbers (" << num1 << ", " << num2 << ", " << num3 << ")" << " is: " << res << endl;
}