/**
 * File: students.h
 * ----------------
 * This program declares all class and functions for managing student's name (in this part, we use C++ array data structure to store
 * the names of students).
 */
#pragma once
#include "header.h"
#define MAX_NUM_STU 100

// assign choice for ease of review
enum CHOICE {
    ADD = 1,
    DELETE = 2,
    DISPL = 3
};

void running();
class Students
{
    string names[MAX_NUM_STU];
    int numOfStudents;
public:
    Students();
    void addStu(string, int);
    void delStu(string);
    void display();
};
void getInput(int &);
void showOutput(Students &, int);