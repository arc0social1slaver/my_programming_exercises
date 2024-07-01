/**
 * File: average-score.h
 * ---------------------
 * This program declares all functions for taking the scores of 10 students (using for loop), calculating the average score and displaying
 * on the screen
 */
#pragma once
#include "header.h"

void taskRunning();
class Students
{
    int numOfStudent;
    double scores[100];
public:
    Students();
    bool getScore();
    double getAvgScore();
    void display(double);
};
void getInput(Students &, int &);