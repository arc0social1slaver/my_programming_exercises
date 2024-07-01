/**
 * File: personal.h
 * --------------------
 * This program declares all classes and functions needed for displaying the personal information
*/
#pragma once
#include "header.h"

void taskRunning();
/**
 * Class: personalInfo
 * ------------------
 * This class will wrap all of the information of the student
*/
class personalInfo {
    string name;
    string mssv;
    string hobby;
    string major;
    public:
    personalInfo();
    personalInfo(string, string, string, string);
    string getName();
    void setName(string);
    string getStuID();
    void setStuID(string);
    string getHob();
    void setHob(string);
    string getMaj();
    void setMaj(string);
    string toString();
};
void showOutput(personalInfo);
void outputFormat(string, string, string, string);
void title();