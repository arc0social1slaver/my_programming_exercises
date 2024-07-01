/**
 * File: mul-stud.cpp
 * -----------------
 * This program specifies all class and functions for taking from user's information of students and displaying its on the screen with
 * the evaluation (passed or not)
 */
#include "mul-stud.h"

/**
 * Function: taskRunning()
 * Usage: taskRunning();
 * ----------------------
 * This function takes from user's information of students and displays its on the screen with the evaluation (passed or not)
*/
void taskRunning()
{
    int choice = -1;
    Students classroom;
    while (true)
    {
        classroom.clear();
        getInput(classroom, choice);
        if (choice == 0)
        {
            break;
        }
        classroom.display();
    }
}
/**
 * Function: getInput(Students &su, int &user)
 * Usage: getInput(classroom, choice);
 * ------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for the names and scores of students (using for loop) until the user 
 * types '-1'. Moreover, if user types score which is less than 0 or greater than 100, the program will also terminate.
 * @param su A class wrapping all information of the students
 * @param user User's choice from the console
*/
void getInput(Students &su, int &user)
{
    cout << "\t\t\t\tProgram displaying information of the students\n";
    cout << "\t\t\t\t----------------------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    fflush(stdin);
    if (user < 1 || user > 10)
    {
        user = 0;
        cout << "The program will terminate\n";
    }
    else
    {
        if (!su.getInfo())
        {
            user = 0;
            cout << "Since the score is out of range, the program will terminate\n";
        }
    }
}
/**
 * Default constructor of class Students
 * ------------------------------------
 * This function sets number of students to 0 and the flag of null information to false
*/
Students::Students()
{
    numOfStud = 0;
    nullInfo = false;
}
/**
 * Member function: getInfo()
 * ------------------------
 * This function prompts the user to type in the name and score of students until the user types -1. Notice that, if user types -1
 * for the score, this function will consider the data has null information
 * @return False if one of the score is out of range (less than 0 or greater than 100) and vice versa
*/
bool Students::getInfo()
{
    string buffer;  // buffer contains value of string from user
    double num = 0; // variable contains value of score from user
    for (int i = 0; i < 100; i++)
    {
        cout << "Please type in the name of the student " << i + 1 << " (Note that if user type in -1, the program will stop asking):\n";
        getline(cin, buffer);
        if (buffer != "-1")
        {
            name[i] = buffer;
            numOfStud++;
            cout << "Please type in the score of the student " << i + 1 << " (Note that if user type in -1, the program will stop asking; however, if the score is out of range, the program will terminate):\n";
            cin >> num;
            fflush(stdin);
            if (num != -1)
            {
                if (num < 0 || num > 100)
                {
                    return false;
                }
                else
                {
                    scores[i] = num;
                    if (scores[i] >= 50)
                    {
                        status[i] = "Passed";
                    }
                    else
                    {
                        status[i] = "Failed";
                    }
                }
            }
            else
            {
                nullInfo = true;
                return true;
            }
        }
        else
        {
            return true;
        }
    }
    return true;
}
/**
 * Member function: clear()
 * ----------------------
 * This function sets number of students to 0 and the flag of null information to false
*/
void Students::clear()
{
    numOfStud = 0;
    nullInfo = false;
}
/**
 * Member function: title().
 * -----------------
 * This function shows the title to the console with the character '-' under it
*/
void Students::title()
{
    cout << setw(30) << left << "Name";
    cout << setw(20) << left << "Score";
    cout << setw(20) << left << "Result" << endl;

    cout << setfill('-');
    cout << setw(70) << "-" << endl;
    cout << setfill(' ');
}
/**
 * Member function: display()
 * -------------------------
 * This function displays the information of students on the screen with the evaluation (passed or not). In case of there is null information,
 * this function lets the score and result of that student be "NULL"
*/
void Students::display()
{
    title();

    for (int i = 0; i < numOfStud; i++)
    {
        cout << setw(30) << left << name[i];
        if (nullInfo)
        {
            if (i == numOfStud - 1)
            {
                cout << setw(20) << left << "NULL";
                cout << setw(20) << left << "NULL" << endl;
            }
            else
            {
                cout << setw(20) << left << scores[i];
                cout << setw(20) << left << status[i] << endl;
            }
        }
        else
        {
            cout << setw(20) << left << scores[i];
            cout << setw(20) << left << status[i] << endl;
        }
    }
    cout << setfill('-');
    cout << setw(70) << "-" << endl;
    cout << setfill(' ');
}