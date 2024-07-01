/**
 * File: students.h
 * ----------------
 * This program declares all class and functions for managing student's name (in this part, we use C++ array data structure to store
 * the names of students).
 */
#pragma once
#include "header.h"

// assign choice for ease of review
enum CHOICE {
    ADD = 1,
    DISPL_BST = 2,
    DISPL = 3
};

void running();
class Students
{
    string* names;
    float* scores;
    int numOfStudents;
public:
    Students();
    ~Students();
    void addStu(string, float, int);
    void delStu(string);
    float getBest();
    void displayBest();
    void display();
};
void getInput(int &);
void showOutput(Students &, int);