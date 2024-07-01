/**
 * File: calculate.h
 * ---------------
 * This program specifies all function needed for getting input/output and calculating the summation, subtraction, division, modulus,
 * multiplication of two numbers
 */
#include "calculate.h"

/**
 * Function: taskRunning().
 * Usage: taskRunning();
 * ---------------------
 * This function gets two numbers from the console and show the result to the console
 * Note: Since the modulus operation only works on integer, two numbers here must be in integer type. Hence, summation, subtraction, modulus,
 * multiplication can be stored in the integer type (we can use result1 to store it) and division can be stored in double type (we can use result2
 * to store it)
 */
void taskRunning()
{
    int choice = -1;
    int firstNum = 0;
    int secondNum = 0;
    int result1 = 0;
    double result2 = 0;
    while (true)
    {
        getInput(firstNum, secondNum, choice);
        if (choice == 0)
        {
            break;
        }
        showOutput(firstNum, secondNum, result1, result2);
    }
}

/**
 * Function: getInput(int &num1, int &num2, int &user).
 * Usage: getInput(firstNum, secondNum, choice);
 * --------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for two integer numbers
 * @param num1 First number from the user
 * @param num2 Second number from the user
 * @param user User's choice from the console
 */
void getInput(int &num1, int &num2, int &user)
{
    cout << "\t\t\t\tProgram calcuting the summation, subtraction, division, modulus, multiplication of two numbers\n";
    cout << "\t\t\t\t----------------------------------------------------------------------------------------------\n";
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
    }
    else
    {
        user = 0;
        cout << "The program will terminate\n";
    }
}
/**
 * Function: showOutput(int num1, int num2, int &res1, double &res2).
 * Usage: showOutput(num1, num2, result1, result2);
 * --------------------------------------------------------------
 * This function shows to the console two numbers typed by the user and calculating the summation, subtraction, division, modulus,
 * multiplication of two numbers respectively.
 * @param num1 First integer number of the user
 * @param num2 Second integer number of the user
 * @param res1 The integer result including sumation, subtraction, modulus, multiplication
 * @param res2 The double result used to store the division of the two numbers
*/
void showOutput(int num1, int num2, int &res1, double &res2)
{
    for (int i = 0; i < 4; i++)
    {
        calcBasedOnChoice(num1, num2, res1, res2, i);
        showBasedOnChoice(num1, num2, res1, res2, i);
    }
}
/**
 * Function: calcBasedOnChoice(int num1, int num2, int &res1, double &res2, int choice).
 * Usage: calcBasedOnChoice(num1, num2, Int_res, Double_res, choice);
 * ------------------------------------------------------------------------------------
 * This function calculates the summation, subtraction, division, modulus, multiplication of two numbers respective (because the choice goes from
 * 0 to 3)
 * @param num1 First integer number of the user
 * @param num2 Second integer number of the user
 * @param res1 The integer result including sumation, subtraction, modulus, multiplication
 * @param res2 The double result used to store the division of the two numbers
 * @param choice The choice in order to decide which operation needed to use
*/
void calcBasedOnChoice(int num1, int num2, int &res1, double &res2, int choice)
{
    switch (choice)
    {
    case ADD:
        res1 = num1 + num2;
        break;
    case SUB:
        res1 = num1 - num2;
        break;
    case DIV:
        res2 = ((double)num1) / num2;
        break;
    case MOD:
        res1 = num1 % num2;
        break;
    case MULTI:
        res1 = num1 * num2;
        break;
    default:
        break;
    }
}
/**
 * Function: showBasedOnChoice(int num1, int num2, int res1, double res2, int choice).
 * Usage: showBasedOnChoice(num1, num2, Int_res, Double_res, choice)
 * ----------------------------------------------------------------------------------
 * This function shows the result of each operation to the console
 * @param num1 First integer number of the user
 * @param num2 Second integer number of the user
 * @param res1 The integer result including sumation, subtraction, modulus, multiplication
 * @param res2 The double result used to store the division of the two numbers
 * @param choice The choice in order to decide which operation needed to show
*/
void showBasedOnChoice(int num1, int num2, int res1, double res2, int choice)
{
    switch (choice)
    {
    case ADD:
        cout << "The sum of two numbers " << num1 << " + " << num2 << " is: " << res1 << endl;
        break;
    case SUB:
        cout << "The subtraction of two numbers " << num1 << " - " << num2 << " is: " << res1 << endl;
        break;
    case DIV:
        cout << "The division of two numbers " << num1 << " / " << num2 << " is: " << res2 << endl;
        break;
    case MOD:
        cout << "The mod of two numbers " << num1 << " % " << num2 << " is: " << res1 << endl;
        break;
    case MULTI:
        cout << "The multiplication of two numbers " << num1 << " * " << num2 << " is: " << res1 << endl;
        break;
    default:
        break;
    }
}
