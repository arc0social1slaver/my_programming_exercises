/**
 * File: uni-col.h
 * ----------------
 * This program declares all class and functions for managing student's information (in this part, we use C++ dynamic array data structure
 * to store the names of students).
 */
#pragma once
#include "header.h"

// assign choice for ease of review
enum CHOICE {
    ADD = 1,
    DISPL_BST = 2,
    DISPL = 3,
    DEL = 4,
    STUDY = 5
};
void running();
class Student
{
    string name;
    string dateOfBirth;
    string nameSchool;
public:
    Student();
    virtual ~Student();
    string getName();
    string getDate();
    string getSchool();
    float* getScores();
    int getNumScores();
    void setName(string);
    void setDate(string);
    void setNameSchool(string);
    void addScore(int);
    void assign(Student &);
    virtual void doAssign() {}
    virtual void takeTest() {}
    virtual void takeExam() {}
    virtual void display() {}
    virtual float getGPA() {return -1;}
    virtual bool getAssignStatus() {return false;}
    virtual bool getTestStatus() {return false;}
    virtual bool getExamStatus() {return false;}
    virtual void setAssignStatus(bool) {}
    virtual void setTestStatus(bool) {}
    virtual void setExamStatus(bool) {}
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
    int numScore;
};
// UniStu derived from Student with different implementations
class UniStu : public Student
{
public:
    UniStu();
    void doAssign();
    void takeTest();
    void takeExam();
    void display();
    float getGPA();
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
    void doAssign();
    void takeTest();
    void takeExam();
    void display();
    float getGPA();
    bool getAssignStatus();
    void setAssignStatus(bool);
    bool getTestStatus();
    void setTestStatus(bool);
    bool getExamStatus();
    void setExamStatus(bool);
};
// StuFactory wraps all class that generate students
class StuFactory {
    public:
    virtual Student* createStudent() = 0;
    virtual ~StuFactory() {}
};
// UniFactory generates students from University
class UniFactory : public StuFactory{
    public:
    Student* createStudent();
};
// CollegFactory generates students from College
class CollegFactory : public StuFactory{
    public:
    Student* createStudent();
};
// Students represents a group of student that needed to be managed
class University
{
    vector<Student*> school[2];
    UniFactory* stuInUni;
    CollegFactory* stuInColleg;
public:
    University();
    ~University();
    void addStu(int, int);
    void delStu(string, int);
    float getBest(int);
    void displayBest(int);
    void display(int);
    void study(string, int);
};
void getInput(int &, int &);
void showOutput(University &, int, int);