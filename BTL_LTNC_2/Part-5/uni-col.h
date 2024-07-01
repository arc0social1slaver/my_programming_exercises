/**
 * File: uni-col.h
 * ----------------
 * This program declares all class and functions for managing student's information (in this part, we use C++ dynamic array data structure
 * to store the names of students).
 */
#pragma once
#include "header.h"

// assign choice for ease of review
enum CHOICE
{
    ADD = 1,
    DISPL = 2,
    DEL = 3
};
void running();
class Student
{
    string name;
    string dateOfBirth;
    string nameSchool;

public:
    Student();
    ~Student();
    string getName();
    string getDate();
    string getSchool();
    void setName(string);
    void setDate(string);
    void setNameSchool(string);
    void assign(Student &);
    float *getScores();
    virtual bool getAssignStatus() { return false; }
    virtual bool getTestStatus() { return false; }
    virtual bool getExamStatus() { return false; }
    virtual void setAssignStatus(bool) {}
    virtual void setTestStatus(bool) {}
    virtual void setExamStatus(bool) {}
    virtual void display() {}

protected:
    int numSem;
    int numCourse;
    int numAssg;
    int numTest;
    int numExam;
    bool takeAssignment[2];
    bool DotakeTest[2];
    bool DotakeExam[2];
    float *scores;
};
// UniStu derived from Student with different implementations
class UniStu : public Student
{
public:
    UniStu();
    void display();
    bool getAssignStatus();
    void setAssignStatus(bool);
    bool getTestStatus();
    void setTestStatus(bool);
    bool getExamStatus();
    void setExamStatus(bool);
};
// CollegStu derived from Student with different implementations
class CollegStu : public Student
{
public:
    CollegStu();
    void display();
    bool getAssignStatus();
    void setAssignStatus(bool);
    bool getTestStatus();
    void setTestStatus(bool);
    bool getExamStatus();
    void setExamStatus(bool);
};
// Students represents a group of student that needed to be managed
class University
{
    Student **pupil;
    int numOfStudentUni;
    int numOfStudentCol;

public:
    University();
    ~University();
    void addStu(int, int);
    void delStu(string, int);
    void display(int);
};
void getInput(int &, int &);
void showOutput(University &, int, int);