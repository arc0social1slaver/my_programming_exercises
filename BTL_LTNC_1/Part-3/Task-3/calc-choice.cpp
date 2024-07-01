/**
 * File: calculate.h
 * ---------------
 * This program specifies all function needed for getting input/output and calculating the summation, subtraction, division, multiplication
 * of two numbers
 */
#include "calc-choice.h"

/**
 * Function: taskRunning().
 * Usage: taskRunning();
 * ---------------------
 * This function gets two numbers from the console and show the result to the console
 */
void taskRunning()
{
    int choice = -1;
    double firstNum = 0;
    double secondNum = 0;
    int op = -1;
    double result = 0;
    while (true)
    {
        getInput(firstNum, secondNum, op, choice);
        if (choice == 0 || op < 0 || op > 3)
        {
            break;
        }
        showOutput(firstNum, secondNum, result, op);
    }
}

/**
 * Function: getInput(int &num1, int &num2, int &op, int &user).
 * Usage: getInput(firstNum, secondNum, operation, choice);
 * --------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for two numbers
 * @param num1 First number from the user
 * @param num2 Second number from the user
 * @param ope The operation from user's choice
 * @param res The result after applying the operation
 * @param user User's choice from the console
 */
void getInput(double &num1, double &num2, int &ope, int &user)
{
    cout << "\t\t\t\tProgram calcuting the summation, subtraction, division, multiplication of two numbers\n";
    cout << "\t\t\t\t-------------------------------------------------------------------------------------\n";
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
        cout << "Please make a choice on operations based on the following:\n";
        cout << "0. Adding operation\n";
        cout << "1. Subtracting operation\n";
        cout << "2. Multiplicating operation\n";
        cout << "3. Dividing operation\n";
        cout << "Otherwise, the program will terminate\n";
        cout << "Please type an operation: ";
        cin >> ope;
        if (ope < 0 || ope > 3)
        {
            cout << "The program will terminate\n";
        }
    }
    else
    {
        user = 0;
        cout << "The program will terminate\n";
    }
}
/**
 * Function: showOutput(double num1, double num2, double &res, int ope).
 * Usage: showOutput(num1, num2, result1, result2);
 * --------------------------------------------------------------
 * This function shows to the console two numbers typed by the user and calculating the summation, subtraction, division, modulus,
 * multiplication of two numbers respectively.
 * @param num1 First number of the user
 * @param num2 Second number of the user
 * @param res The result after applying the operation
 * @param ope The operation from user's choice
 */
void showOutput(double num1, double num2, double &res, int ope)
{
    calcBasedOnChoice(num1, num2, res, ope);
    showBasedOnChoice(num1, num2, res, ope);
}
/**
 * Function: calcBasedOnChoice(int num1, int num2, int &res1, double &res2, int choice).
 * Usage: calcBasedOnChoice(num1, num2, Int_res, Double_res, choice);
 * ------------------------------------------------------------------------------------
 * This function calculates the summation, subtraction, division, modulus, multiplication of two numbers respective (because the choice goes from
 * 0 to 3)
 * @param num1 First number of the user
 * @param num2 Second number of the user
 * @param res The result after applying the operation
 * @param choice The choice in order to decide which operation needed to use
 */
void calcBasedOnChoice(double num1, double num2, double &res, int choice)
{
    switch (choice)
    {
    case ADD:
        res = num1 + num2;
        break;
    case SUB:
        res = num1 - num2;
        break;
    case DIV:
        res = num1 / num2;
        break;
    case MULTI:
        res = num1 * num2;
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
 * @param num1 First number of the user
 * @param num2 Second number of the user
 * @param res The result after applying the operation
 * @param choice The choice in order to decide which operation needed to show
 */
void showBasedOnChoice(double num1, double num2, double res, int choice)
{
    switch (choice)
    {
    case ADD:
        cout << "The sum of two numbers " << num1 << " + " << num2 << " is: " << res << endl;
        break;
    case SUB:
        cout << "The subtraction of two numbers " << num1 << " - " << num2 << " is: " << res << endl;
        break;
    case DIV:
        cout << "The division of two numbers " << num1 << " / " << num2 << " is: " << res << endl;
        break;
    case MULTI:
        cout << "The multiplication of two numbers " << num1 << " * " << num2 << " is: " << res << endl;
        break;
    default:
        break;
    }
}