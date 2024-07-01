/**
 * File: average-score.cpp
 * ---------------------
 * This program specifies all class and functions for taking the scores of 10 students (using for loop), calculating the average score and
 * displaying on the screen
 */
#include "average-score.h"

/**
 * Function: taskRunning()
 * Usage: taskRunning();
 * --------------------
 * This function takes the scores of 10 students (using for loop), then calculates the average score and displays on the screen
*/
void taskRunning()
{
    Students classroom;
    int choice = -1;
    while (true)
    {
        getInput(classroom, choice);
        if (choice == 0)
        {
            break;
        }
        double averageScore = classroom.getAvgScore();
        classroom.display(averageScore);
    }
}
/**
 * Function: getInput(Students &su, int &user)
 * Usage: getInput(classroom, choice);
 * -------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for the scores of 10 students (using for loop). Moreover, if user types
 * score which is less than 0 or greater than 100, the program will also terminate
 * @param su A class wrapping all information of the students
 * @param user User's choice from the console
*/
void getInput(Students &su, int &user)
{
    cout << "\t\t\t\tProgram calcuting the average score of 10 students\n";
    cout << "\t\t\t\t--------------------------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user < 1 || user > 10)
    {
        user = 0;
        cout << "The program will terminate\n";
    }
    else
    {
        if (!su.getScore())
        {
            user = 0;
            cout << "Since the score is out of range, the program will terminate\n";
        }
    }
}
/**
 * Default constructor of class Students
 * ------------------------------------
 * This function set number of students to 10
*/
Students::Students()
{
    numOfStudent = 10;
}
/**
 * Member function: getScore()
 * Usage: classroom.getScore()
 * --------------------------
 * This function gets the score of each student
 * @return False if one of the score is out of bound and vice versa
*/
bool Students::getScore()
{
    for (int i = 0; i < numOfStudent; i++)
    {
        cout << "Please type in the score of student " << i + 1 << " (Note that if the score is less than 0 or greater than 100, the program will terminate):\n";
        cin >> scores[i];
        if (scores[i] < 0 || scores[i] > 100)
        {
            return false;
        }
    }
    return true;
}
/**
 * Member function: getAvgScore()
 * Usage: averageResult= classroom.getAvgScore()
 * --------------------------------------------
 * This function calculates the average score of all students
 * @return The average score of all students
*/
double Students::getAvgScore()
{
    double avg = 0;
    for (int i = 0; i < numOfStudent; i++)
    {
        avg += scores[i];
    }
    return avg / numOfStudent;
}
/**
 * Member function: display(double avg)
 * Usage: classroom.display(averageResult);
 * ---------------------------------------
 * This function displays the average score to the console
 * @param avg The average score of all students
*/
void Students::display(double avg)
{
    cout << "The average score of " << numOfStudent << " students is: " << avg << endl;
}