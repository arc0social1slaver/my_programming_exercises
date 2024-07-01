/**
 * File: personal.cpp
 * ------------------
 * This program specifies all function needed for displaying the personal information
 */
#include "personal.h"

/**
 * Function: taskRunning().
 * Usage: taskRunning();
 * -----------------------
 * This function declares the information and shows the information to the console
*/
void taskRunning()
{
    personalInfo myInfo;
    showOutput(myInfo);
}
/**
 * Function: showOutput(personalInfo info).
 * Usage: showOutput(myInfo);
 * ----------------------------------------
 * This function shows the information with its tile to the console
 * @param info The class representing the information of the student
*/
void showOutput(personalInfo info)
{
    string name = info.getName();
    string stuId = info.getStuID();
    string hobby = info.getHob();
    string major = info.getMaj();
    title();
    outputFormat("Name", "Student_ID", "Hobby", "Major");
    outputFormat(name, stuId, hobby, major);
}
/**
 * Function: title().
 * Usage: title();
 * -----------------
 * This function shows the title to the console with the character '-' under it
*/
void title()
{
    cout << setw(60) << right << "Personal information" << endl;
    
    cout << setfill('-');
    cout << setw(95) << "-" << endl;
    cout << setfill(' ');
}
/**
 * Function: outputFormat(string name, string studId, string hobby, string major).
 * Usage: outputFormat(name, stuId, hobby, major);
 * ------------------------------------------------------------------------------
 * This function shows the information in a table format. Every row is seperated by the line containing '-'. Moreover, we can use this function
 * to shows the title of each column in the table
 * @param name The name of the student/The "Name" column
 * @param stuId The student ID/ The "Student_ID" column
 * @param hobby The hobby of the student/ The "Hobby" column
 * @param major The major of the student/ The "Major" column
*/
void outputFormat(string name, string studId, string hobby, string major)
{
    cout << setw(30) << left << name;
    cout << setw(20) << left << studId;
    cout << setw(30) << left << hobby;
    cout << setw(15) << left << major << endl;

    cout << setfill('-');
    cout << setw(95) << "-" << endl;
    cout << setfill(' ');
}
/**
 * Default constructor of class personalInfo
 * ----------------------------------------
 * This function assigns the author's information to the variables
*/
personalInfo::personalInfo()
{
    name = "Nguyen Thanh Phat";
    mssv = "2252605";
    hobby = "Listening to music";
    major = "Computer Science";
}
/**
 * Constructor of class personalInfo
 * ---------------------------------
 * This function assigns specific information to the variables
 * @param nameVal The name needed to assign
 * @param stuId The student ID needed to assign
 * @param hobVal The hobby needed to assign
 * @param majVal The major needed to assign
*/
personalInfo::personalInfo(string nameVal, string stuId, string hobVal = "", string majVal = "")
{
    name = nameVal;
    mssv = stuId;
    hobby = hobVal;
    major = majVal;
}
/**
 * Getter of the name of the student
 * ---------------------------------
 * @return The name of the student
*/
string personalInfo::getName()
{
    return name;
}
/**
 * Setter of the name of the student
 * --------------------------------
 * @param nameVal The value that will be assigned to the name of the student
*/
void personalInfo::setName(string nameVal)
{
    name = nameVal;
}
/**
 * Getter of the student ID
 * ------------------------
 * @return The student ID
*/
string personalInfo::getStuID()
{
    return mssv;
}
/**
 * Setter of the student ID
 * ------------------------
 * @param stuID The value that will be assigned to the student ID
*/
void personalInfo::setStuID(string stuID)
{
    mssv = stuID;
}
/**
 * Getter of the hobby
 * ------------------
 * @return The hobby of the student
*/
string personalInfo::getHob()
{
    return hobby;
}
/**
 * Setter of the hobby
 * ------------------
 * @param hobVal The value that will be assigned to the hobby of the student
*/
void personalInfo::setHob(string hobVal)
{
    hobby = hobVal;
}
/**
 * Getter of the major of the student
 * ----------------------------------
 * @return The major of the student
*/
string personalInfo::getMaj()
{
    return major;
}
/**
 * Setter of the major of the student
 * ----------------------------------
 * @param majVal The value that will be assigned to the major of the student
*/
void personalInfo::setMaj(string majVal)
{
    major = majVal;
}
/**
 * Function: toString().
 * Usage: string myinfo= info.toString();
 * --------------------------------------
 * This function returns a string that contains all of our information
 * @return All of the information in a class
*/
string personalInfo::toString()
{
    string my_info = name + "\t\t" + mssv + "\t\t" + hobby + "\t\t" + major + "\n";
    return my_info;
}