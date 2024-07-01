/**
 * File: triple.cpp
 * ---------------
 * This program specifies all class and functions for taking for user three numbers, calculating sumTripple, mulTripple, aveTriple and
 * displaying on the console
 */
#include "triple.h"

/**
 * Function: taskRunning()
 * Usage: taskRunning();
 * ---------------------
 * This function takes for user three numbers, calculates sumTripple, mulTripple, aveTriple and displays on the console. Note that, if user types
 * in -1, the program will terminate
 */
void taskRunning()
{
    float firstNum = 0;
    float secondNum = 0;
    float thirdNum = 0;
    int choice = 0;
    while (true)
    {
        getInput(firstNum, secondNum, thirdNum, choice);
        if (choice == -1)
        {
            break;
        }
        showOutput(firstNum, secondNum, thirdNum);
    }
}
/**
 * Function: getInput(float &num1, float &num2, float &num3, int &user)
 * Usage: getInput(firstNum, secondNum, thirdNum, choice);
 * --------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types -1, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for three float numbers. Note that, if the user types -1, the program will
 * terminate
 * @param num1 The first number of the user
 * @param num2 The second number of the user
 * @param num3 The third number of the user
 * @param user User's choice from the console
 */
void getInput(float &num1, float &num2, float &num3, int &user)
{
    cout << "\t\t\t\tProgram displaying the summation, multiplication and average of three float numbers\n";
    cout << "\t\t\t\t-----------------------------------------------------------------------------------\n";
    cout << "Please make a choice by typing an integer based on the following:\n";
    cout << "-1. Terminate the program\n";
    cout << "Otherwise, start the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user == -1)
    {
        cout << "The program will terminate\n";
    }
    else
    {
        cout << "Please type in the first number (Note that, if user types in -1, the program wil terminate):\n";
        cin >> num1;
        if (num1 == -1)
        {
            user = -1;
            cout << "The program will terminate\n";
        }
        else
        {
            cout << "Please type in the second number (Note that, if user types in -1, the program wil terminate):\n";
            cin >> num2;
            if (num2 == -1)
            {
                user = -1;
                cout << "The program will terminate\n";
            }
            else
            {
                cout << "Please type in the third number (Note that, if user types in -1, the program wil terminate):\n";
                cin >> num3;
                if (num3 == -1)
                {
                    user = -1;
                    cout << "The program will terminate\n";
                }
            }
        }
    }
}
/**
 * Function: showOutput(float num1, float num2, float num3)
 * Usage: showOutput(firstNum, secondNum, thirdNum);
 * ------------------------------------------------------
 * This function displays sumTripple, mulTripple, aveTriple of three float numbers.
 * @param num1 The first number of the user
 * @param num2 The second number of the user
 * @param num3 The third number of the user
 */
void showOutput(float num1, float num2, float num3)
{
    cout << "The sum of " << num1 << ", " << num2 << ", " << num3 << " is: " << sumTripple(num1, num2, num3) << endl;
    cout << "The multiplication of " << num1 << ", " << num2 << ", " << num3 << " is: " << mulTripple(num1, num2, num3) << endl;
    cout << "The average of " << num1 << ", " << num2 << ", " << num3 << " is: " << aveTripple(num1, num2, num3) << endl;
}
/**
 * Function: sumTripple(float num1, float num2, float num3)
 * -------------------------------------------------------
 * @param num1 The first number of the user
 * @param num2 The second number of the user
 * @param num3 The third number of the user
 * @return The sum of three float numbers of user
 */
float sumTripple(float num1, float num2, float num3)
{
    return num1 + num2 + num3;
}

/**
 * Function: mulTripple(float num1, float num2, float num3)
 * -------------------------------------------------------
 * @param num1 The first number of the user
 * @param num2 The second number of the user
 * @param num3 The third number of the user
 * @return The multiplication of three float numbers of user
 */
float mulTripple(float num1, float num2, float num3)
{
    return num1 * num2 * num3;
}

/**
 * Function: aveTripple(float num1, float num2, float num3)
 * -------------------------------------------------------
 * @param num1 The first number of the user
 * @param num2 The second number of the user
 * @param num3 The third number of the user
 * @return The average of three float numbers of user
 */
float aveTripple(float num1, float num2, float num3)
{
    return sumTripple(num1, num2, num3) / 3;
}