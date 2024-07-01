/**
 * File: mul-stud.h
 * ----------------
 * This program declares all class and functions for taking from user's information of students and displaying its on the screen with
 * the evaluation (passed or not)
 */
#pragma once
#include "header.h"

void taskRunning();
/**
 * Class: Students
 * --------------
 * This class wraps all of name and score of the students
*/
class Students
{
    double scores[100];
    string name[100];
    string status[100];
    int numOfStud;
    bool nullInfo; // The flag of the student that does not have score
    static void title();
public:
    Students();
    bool getInfo();
    void display();
    void clear();
};
void getInput(Students &, int &);