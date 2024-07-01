/**
 * File: volume.cpp
 * ----------------
 * This program specifies all functions needed for getting the radius, height of a cylinder, calculating its volume and displaying the volume
 * on the console
 */
#include "volume.h"

/**
 * Function: taskRunning().
 * Usage: taskRunning()
 * -----------------------
 * This function gets the radius, height of a cylinder, calculates its volume and displays the volume on the console. Moreover, if one of the two
 * values is less than or equals to 0, the fucntion will ask the user to input the radius and height of a cylinder again.
*/
void taskRunning()
{
    double radius = 0;
    double height = 0;
    double volume = 0;
    int choice = -1;
    while (true)
    {
        getInput(radius, height, choice);
        if (choice == 0)
        {
            break;
        }
        if (radius > 0 && height > 0)
        {
            volume = getVolume(radius, height);
            showOutput(radius, height, volume);
        }
    }
}

/**
 * Function: getInput(double &num1, double &num2, int &user)
 * Usage: getInput(radius, height, choice);
 * --------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for the radius and height of the cylinder. If one of the two values is 
 * less than or equals to 0, an error message will be printed on the screen
 * @param num1 The radius of a cylinder
 * @param num2 The height of a cylinder
 * @param user User's choice from the console
 */
void getInput(double &num1, double &num2, int &user)
{
    cout << "\t\t\t\tProgram calcuting volume of a cylinder\n";
    cout << "\t\t\t\t--------------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user >= 1 && user <= 10)
    {
        cout << "Please type the radius of a cylinder (Note that your number should not less than or equal to 0):\n";
        cin >> num1;
        if (num1 <= 0)
        {
            cout << "The value of radius is invalid\n";
        }
        else
        {
            cout << "Please type the height of a cylinder (Note that your number should not less than 0):\n";
            cin >> num2;

            if (num2 <= 0)
            {
                cout << "The value of height is invalid\n";
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
 * Function: getVolume(double num1, double num2)
 * Usage: volume = getVolume(radius, height);
 * --------------------------------------------
 * This function calculates the volume of a cylinder based on the radius and height (Note that we let PI values equals to 3.14159265)
 * @param num1 The radius of a cylinder
 * @param num2 The height of a cylinder
 * @return The volume of a cylinder
*/
double getVolume(double num1, double num2)
{
    return PI * num1 * num1 * num2;
}
/**
 * Function: showOutput(double num1, double num2, double res).
 * Usage: showOutput(radius, height, volume);
 * ---------------------------------------------
 * This function shows the information in a table format. Every row is seperated by the line containing '-'. Moreover, we can use this function
 * to shows the title of each column in the table
 * @param num1 The radius of a cylinder
 * @param num2 The height of a cylinder
 * @param res The volume of a cylinder
*/
void showOutput(double num1, double num2, double res)
{
    cout << setw(20) << left << "Radius";
    cout << setw(20) << left << "Height";
    cout << setw(20) << left << "Volume" << endl;

    cout << setfill('-');
    cout << setw(60) << "-" << endl;
    cout << setfill(' ');

    cout << setw(20) << left << num1;
    cout << setw(20) << left << num2;
    cout << setw(20) << left << res << endl;

    cout << setfill('-');
    cout << setw(60) << "-" << endl;
    cout << setfill(' ');
}