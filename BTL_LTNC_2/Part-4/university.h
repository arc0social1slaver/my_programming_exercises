/**
 * File: university.h
 * ----------------
 * This program declares all class and functions for managing student's name (in this part, we use C++ dynamic array data structure to store
 * the names of students).
 */
#pragma once
#include "header.h"

// assign choice for ease of review
enum CHOICE {
    ADD = 1,
    DISPL_BST = 2,
    DISPL = 3,
    DEL = 4
};

void running();
class Student
{
    string name;
    float score;
public:
    Student(string, float);
    ~Student() {}
    string getName();
    float getScore();
    void setName(string);
    void setScore(float);
    void assign(Student &);
};
class University
{
    Student* pupil;
    int numOfStudents;
    string uniName;
public:
    University();
    ~University();
    void setUniName(string);
    void addStu(string, float, int);
    void delStu(string);
    float getBest();
    void displayBest();
    void display();
};
void getInput(int &);
void showOutput(University &, int);