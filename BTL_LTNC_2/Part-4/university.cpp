/**
 * File: university.cpp
 * ----------------
 * This program specifies all class and functions for managing student's name (in this part, we use C++ dynamic array data structure to store
 * the names of students).
 */
#include "university.h"

/**
 * Function: running()
 * -----------------
 * This function prompts the user to manage their student's manangement system.
 */
void running()
{
    University myUni;
    int choice = -1;
    string uniName;
    cout << "\t\tStudent Management program\n";
    cout << "\t\t--------------------------\n";
    do
    {
        cout << "Please enter your university's name: ";
        getline(cin, uniName);
        if (uniName == "")
        {
            cout << "You have not entered the name\n";
        }
        else
        {
            myUni.setUniName(uniName);
        }
    } while (uniName == "");
    while (true)
    {
        getInput(choice);
        if (choice == 0)
        {
            break;
        }
        showOutput(myUni, choice);
    }
}
/**
 * Constructor of class Student
 * ---------------------------
 * This function initializes a students based on the parameters
 * @param nameVal The name of a student
 * @param scoreVal The score of a student
 */
Student::Student(string nameVal = "", float scoreVal = -1)
{
    name = nameVal;
    score = scoreVal;
}
/**
 * Getter of the name of student
 * @return The name of the student
 */
string Student::getName()
{
    return name;
}
/**
 * Getter of the score of student
 * @return The score of the student
 */
float Student::getScore()
{
    return score;
}
/**
 * Setter of the name of student
 * @param nameVal The new name of the student
 */
void Student::setName(string nameVal)
{
    name = nameVal;
}
/**
 * Setter of the name of student
 * @param scoreVal The new score of the student
 */
void Student::setScore(float scoreVal)
{
    score = scoreVal;
}
/**
 * Member function: assign(Student &partner)
 * ---------------------------------------
 * This function assigns the name and score of other student.
 * @param partner The student that assigns the value
 */
void Student::assign(Student &partner)
{
    name = partner.getName();
    score = partner.getScore();
}
/**
 * Constructor of University
 * ----------------------
 * This function sets number of Student to 0 and let the pointer pupil to null pointer.
 */
University::University()
{
    pupil = nullptr;
    numOfStudents = 0;
}
/**
 * Desturctor of University
 * ----------------------
 * This fucntion free the memory of pupil.
 */
University::~University()
{
    delete[] pupil;
}
/**
 * Function : addStu(string name, int pos)
 * --------------------------------------
 * This function allows user to add a new student with the score to the system. If the number of students is full or the postion or the score
 * is out of range, this function will not allow to input.
 * @param name The name's of new student
 * @param diem The score's of new student
 * @param pos The position of new student in the system (starting from 0)
 */
void University::addStu(string name, float diem, int pos)
{
    if (pos < 0 || pos >= numOfStudents + 1)
    {
        cout << "Your position is out of range\n";
    }
    else if (diem < 0 || diem > 100)
    {
        cout << "Your score is invalid\n";
    }
    else if (name == "")
    {
        cout << "Inalid name\n";
    }
    else
    {
        numOfStudents++;
        Student *newPupil = new Student[numOfStudents];
        for (int i = 0; i < numOfStudents - 1; i++)
        {
            newPupil[i].assign(pupil[i]);
        }
        for (int i = numOfStudents - 2; i >= pos; i--)
        {
            newPupil[i + 1].assign(newPupil[i]);
        }
        newPupil[pos].setName(name);
        newPupil[pos].setScore(diem);
        delete[] pupil;
        pupil = newPupil;
    }
}
/**
 * Funtion: delStu(string name)
 * ---------------------------
 * This function deletes a student based on the student's name. If the system does not have any student or the name does not match,
 * this funtion will not allow to delete.
 * @param name The name of student's needed to delete
 */
void University::delStu(string name)
{
    if (numOfStudents == 0)
    {
        cout << "There is no one to remove in the " << uniName << " university" << endl;
    }
    else
    {
        int position = -1;
        for (int i = 0; i < numOfStudents; i++)
        {
            if (pupil[i].getName() == name)
            {
                position = i;
                break;
            }
        }
        if (position == -1)
        {
            cout << "The name " << name << " is not found in our system\n";
        }
        else
        {
            for (int i = position + 1; i < numOfStudents; i++)
            {
                pupil[i - 1].assign(pupil[i]);
            }
            numOfStudents--;
            Student *newPupil = new Student[numOfStudents];
            for (int i = 0; i < numOfStudents; i++)
            {
                newPupil[i].assign(pupil[i]);
            }
            delete[] pupil;
            pupil = nullptr;
            pupil = newPupil;
        }
    }
}
/**
 * Member function: display()
 * ------------------
 * This function displays all current students in the system. Note that: if the name of student is an empty string, the system will ignore that
 * student.
 */
void University::display()
{
    if (numOfStudents == 0)
    {
        cout << "There is no one in the university " << uniName << endl;
    }
    else
    {
        for (int i = 0; i < numOfStudents; i++)
        {
            string name = pupil[i].getName();
            if (name != "")
            {
                float score = pupil[i].getScore();
                cout << "The student " << i + 1 << "'s name is " << name << " has the score: " << score << endl;
            }
        }
    }
}
/**
 * Member function: getBest()
 * ------------------------
 * @return The highest score recorded in the system
 */
float University::getBest()
{
    float highestScore = -1;
    for (int i = 0; i < numOfStudents; i++)
    {
        float score = pupil[i].getScore();
        if (score > highestScore)
        {
            highestScore = score;
        }
    }
    return highestScore;
}
/**
 * Member function: displayBest()
 * -----------------------------
 * This function shows the student(s) with the highest score.
 */
void University::displayBest()
{
    if (numOfStudents == 0)
    {
        cout << "There is no one in the university " << uniName << endl;
    }
    else
    {
        float studHighest = getBest();
        for (int i = 0; i < numOfStudents; i++)
        {
            string name = pupil[i].getName();
            if (name != "")
            {
                float score = pupil[i].getScore();
                if (score == studHighest)
                {
                    cout << "The student " << i + 1 << "'s name is: " << name << " has the highest score with " << score << endl;
                }
            }
        }
    }
}
/**
 * Setter of the university's
 * @param The new name of the university
*/
void University::setUniName(string uniVal)
{
    uniName = uniVal;
}
/**
 * Function: getInput(int &user)
 * ----------------------------
 * This function prompts the user to make a choice for managing the students'. If the user inputs invalid number, the program will terminate
 * @param user The choice of user.
 */
void getInput(int &user)
{
    cout << "Please make a choice (0 to quit):\n";
    cout << "1. Add a student to the system.\n";
    cout << "2. Display all students that has highest score in the system.\n";
    cout << "3. Display all students in the system.\n";
    cout << "4. Delete a student in the system.\n";
    cout << "Your choice is: ";
    cin >> user;
    cin.ignore();
    if (user < 1 || user > 4)
    {
        user = 0;
    }
}
/**
 * Funtion: showOutput(Student &su,int &user)
 * -----------------------------------------
 * This function executes the user's request based on their choice
 * @param su The student mangagement system
 * @param user The user's choice
 */
void showOutput(University &su, int user)
{
    string name;
    float score = -1;
    int position = -1;
    switch (user)
    {
    case ADD:
        cout << "Please type in the name of the student that you want to add: ";
        getline(cin, name);
        cout << "Please type in the score of the student that you want to add: ";
        cin >> score;
        cout << "Please type in the position that you want to add: ";
        cin >> position;
        su.addStu(name, score, position);
        break;
    case DISPL:
        su.display();
        break;
    case DISPL_BST:
        su.displayBest();
        break;
    case DEL:
        cout << "Please type in the name of the student that you want to delete: ";
        getline(cin, name);
        su.delStu(name);
        break;
    default:
        break;
    }
}