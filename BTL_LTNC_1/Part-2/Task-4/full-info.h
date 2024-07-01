/**
 * File: full-info.h
 * -----------------
 * This programs declares all class and functions for taking from user input basic information of a student including full
 * name, day of birth, hometown, major, … and displaying this information on the screen
 */
#pragma once
#include "header.h"

// When taking from user inputs, assignning each information for ease of review
enum input
{
    NAME,
    DAY,
    MONTH,
    YEAR,
    HOMETOWN,
    MAJOR
};

void taskRunning();
/**
 * Class: personalInfo
 * ------------------
 * This class will wrap all of the information of the student
 */
class personalInfo
{
    string name;
    string day;
    string month;
    string year;
    string hometown;
    string major;
    static int convertToInt(string);
    static bool checkDigit(string);
public:
    personalInfo();
    personalInfo(string, string, string, string, string, string);
    string getName();
    void setName(string);
    string getDay();
    void setDay(string);
    string getMonth();
    void setMonth(string);
    string getYear();
    void setYear(string);
    string getHometown();
    void setHometown(string);
    string getMaj();
    void setMaj(string);
    void reset();
    string toString();
    bool validateDate();
};
void getInput(personalInfo &, int &);
void showOutput(personalInfo);
void outputFormat(string, string, string, string);
void title();
void inputFormat(personalInfo &, string &, int &);