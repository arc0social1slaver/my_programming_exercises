/**
 * File: full-info.cpp
 * -------------------
 * This programs specifies all class and functions for taking from user input basic information of a student including full
 * name, day of birth, hometown, major, … and displaying this information on the screen
 */
#include "full-info.h"

/**
 * Function: taskRunning()
 * Usage: taskRunning()
 * ----------------------
 * This function takes from user input basic information of a student including full name, day of birth, hometown, major, … and displays
 * this information on the screen. Moreover, if user types incorrect date (for example the day is less than 0 or the date contains letter),
 * this function will clear all information and ask user to type in again
*/
void taskRunning()
{
    personalInfo myinfo;
    int choice = -1;
    while (true)
    {
        getInput(myinfo, choice);
        if (choice == 0)
        {
            break;
        }
        if (myinfo.validateDate())
        {
            showOutput(myinfo);
        }
        else
        {
            myinfo.reset();
            cout << "Your date of birth is invalid" << endl;
        }
    }
}
/**
 * Default constructor of class personalInfo
 * ----------------------------------------
 * This function assigns empty string to the variables
 */
personalInfo::personalInfo()
{
    name = day = month = year = hometown = major = "";
}
/**
 *  Constructor of class personalInfo
 * ---------------------------------
 * This function assigns specific information to the variables
 * @param nameVal The name of the student
 * @param dayVal The day in date of birth of the student
 * @param monthVal The month in date of birth of the student
 * @param yearVal The year in date of birth of the student
 * @param homeVal The hometown of the student
 * @param majVal The major of the student
 */
personalInfo::personalInfo(string nameVal, string dayVal = "", string monthVal = "", string yearVal = "", string homeVal = "", string majVal = "")
{
    name = nameVal;
    day = dayVal;
    month = monthVal;
    year = yearVal;
    hometown = homeVal;
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
 * Getter of the day in date of birth of the student
 * -------------------------------------------------
 * @return The day in date of birth of the student
 */
string personalInfo::getDay()
{
    return day;
}
/**
 * Setter of the day in date of birth of the student
 * ------------------------------------------------
 * @param The day in date of birth of the student
 */
void personalInfo::setDay(string dayVal)
{
    day = dayVal;
}
/**
 * Getter of the month in date of birth of the student
 * ---------------------------------------------------
 * @return The month in date of birth of the student
 */
string personalInfo::getMonth()
{
    return month;
}
/**
 * Setter of the month in date of birth of the student
 * ---------------------------------------------------
 * @param monthVal The month in date of birth of the student
 */
void personalInfo::setMonth(string monthVal)
{
    month = monthVal;
}
/**
 * Getter of the year in date of birth of the student
 * -------------------------------------------------
 * @return The year in date of birth of the student
 */
string personalInfo::getYear()
{
    return year;
}
/**
 * Setter of the year in date of birth of the student
 * -------------------------------------------------
 * @param yearVal The year in date of birth of the student
 */
void personalInfo::setYear(string yearVal)
{
    year = yearVal;
}
/**
 * Getter of the hometown of the student
 * ------------------------------------
 * @return The hometown of the student
 */
string personalInfo::getHometown()
{
    return hometown;
}
/**
 * Setter of the hometown of the student
 * ------------------------------------
 * @param homeVal The hometown of the student
 */
void personalInfo::setHometown(string homeVal)
{
    hometown = homeVal;
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
    string my_info = name + "\t\t" + day + "\t\t" + month + "\t\t" + year + "\t\t" + major + "\n";
    return my_info;
}
/**
 * Member function: reset()
 * Usage: info.reset();
 * ----------------------
 * This function set all information to empty string
*/
void personalInfo::reset()
{
    name = day = month = year = hometown = major = "";
}
/**
 * Function: convertToInt(string s)
 * Usage: converToInt(numString);
 * -------------------------------
 * This function converts a string to an integer by iterating through the string and adding it to the return value when encoutering a number
 * letter.
 * @param s A string contains number letter
 * @return An integer that contains all number in a string
*/
int personalInfo::convertToInt(string s)
{
    int num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char a = s[i];
        if (a >= '0' && a <= '9')
        {
            num = num * 10 + (a - '0');
        }
    }
    return num;
}
/**
 * Member function: validateDate()
 * Usage: info.validateDate();
 * ------------------------------
 * This function checks the user's date of birth whether the date is out of range or not
 * @return True if the user's date of birth is valid and vice versa
*/
bool personalInfo::validateDate()
{
    if (!checkDigit(day) || !checkDigit(month) || !checkDigit(year))
    {
        return false;
    }

    int Int_year = convertToInt(year);
    int Int_month = convertToInt(month);
    int Int_day = convertToInt(day);

    if (Int_year > 0 && Int_year < 2025)
    {
        if (Int_month > 0 && Int_month < 13)
        {
            if (Int_day > 0 && Int_day < 32)
            {
                if (Int_month == 2)
                {
                    if (Int_day <= 29)
                    {
                        return true;
                    }
                }
                else
                {
                    return true;
                }
            }
        }
    }
    return false;
}
/**
 * Member function: checkDigit(string a)
 * Usage: checkDigit(numString);
 * ------------------------------------
 * This function checks whether the string contains all number letter or not
 * @param a A string that needed to check
 * @return True if the string contains all number letter and vice versa
*/
bool personalInfo::checkDigit(string a)
{
    for (int i=0; i< a.length();i++)
    {
        char c = a[i];
        if (c < '0' || c > '9')
        {
            return false;
        }
    }
    return true;
}
/**
 * Function: getInput(personalInfo &info, int &user)
 * Usage: getInput(myinfo, choice);
 * --------------------------------------------------------------
 * This function prompts the user to type in their choice (if the user types 0, the program will terminate; otherwise, the program will start)
 * After that, if the program starts, this function will ask the user for information.
 * @param info A class storing the user's information
 * @param user User's choice from the console
 */
void getInput(personalInfo &info, int &user)
{
    string buffer;
    cout << "\t\t\t\tProgram displaying the information of the student\n";
    cout << "\t\t\t\t-------------------------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    fflush(stdin);
    if (user >= 1 && user <= 10)
    {
        for (int i = 0; i < 6; i++)
        {
            inputFormat(info, buffer, i);
        }
    }
    else
    {
        user = 0;
        cout << "The program will terminate\n";
    }
}
/**
 * Function: inputFormat(personalInfo &info, string &buf, int &user)
 * Usage: inputFormat(info, buffer, i);
 * -----------------------------------------------------------------
 * This function prompts the user to type in information
 * @param info A class storing information of the student
 * @param buf A string used to store input from user
 * @param user The choice in order to decide which information needed to be typed in
*/
void inputFormat(personalInfo &info, string &buf, int &user)
{
    switch (user)
    {
    case NAME:
        cout << "Please type in your name:\n";
        getline(cin, buf);
        info.setName(buf);
        break;
    case DAY:
        cout << "Please type in your day in the date of birth of the student (the format should be a number between 1 and 31):\n";
        getline(cin, buf);
        info.setDay(buf);
        break;
    case MONTH:
        cout << "Please type in your month in the date of birth of the student (the format should be a number between 1 and 12):\n";
        getline(cin, buf);
        info.setMonth(buf);
        break;
    case YEAR:
        cout << "Please type in your year in the date of birth of the student (the format should be a number less than 2025):\n";
        getline(cin, buf);
        info.setYear(buf);
        break;
    case HOMETOWN:
        cout << "Please type in your hometown:\n";
        getline(cin, buf);
        info.setHometown(buf);
        break;
    case MAJOR:
        cout << "Please type in your major:\n";
        getline(cin, buf);
        info.setMaj(buf);
        break;
    }
    buf = "";
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
    string date = info.getMonth() + "/" + info.getDay() + "/" + info.getYear();
    string hometown = info.getHometown();
    string major = info.getMaj();

    title();
    outputFormat("Name", "Date of birth", "Hometown", "Major");
    outputFormat(name, date, hometown, major);
}
/**
 * Function: outputFormat(string name, string date, string hometown, string major).
 * Usage: outputFormat(name, date, hometown, major);
 * ------------------------------------------------------------------------------
 * This function shows the information in a table format. Every row is seperated by the line containing '-'. Moreover, we can use this function
 * to shows the title of each column in the table
 * @param name The name of the student/The "Name" column
 * @param date The date of birth/ The "Date of birth" column
 * @param hometown The hometown of the student/ The "Hometown" column
 * @param major The major of the student/ The "Major" column
*/
void outputFormat(string name, string date, string hometown, string major)
{
    cout << setw(30) << left << name;
    cout << setw(20) << left << date;
    cout << setw(30) << left << hometown;
    cout << setw(15) << left << major << endl;

    cout << setfill('-');
    cout << setw(95) << "-" << endl;
    cout << setfill(' ');
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