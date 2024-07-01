/**
 * File: students.cpp
 * ----------------
 * This program specifies all class and functions for managing student's name (in this part, we use C++ array data structure to store
 * the names of students).
 */
#include "students.h"

/**
 * Function: running()
 * -----------------
 * This function prompts the user to manage their student's manangement system.
 */
void running()
{
    Students classroom;
    int choice = -1;
    cout << "\t\tStudent Management program\n";
    cout << "\t\t--------------------------\n";
    while (true)
    {
        getInput(choice);
        if (choice == 0)
        {
            break;
        }
        showOutput(classroom, choice);
    }
}
/**
 * Constructor of Students
 * ----------------------
 * This function sets number of Student to 0
 */
Students::Students()
{
    numOfStudents = 0;
}
/**
 * Function : addStu(string name, int pos)
 * --------------------------------------
 * This function allows user to add a new student to the system. If the number of students is full or the postion is out of range, this function
 * will not allow to input.
 * @param name The name's of new student
 * @param pos The position of new student in the system (starting from 0)
 */
void Students::addStu(string name, int pos)
{
    if (numOfStudents == MAX_NUM_STU)
    {
        cout << "Our classroom is full\n";
    }
    else
    {
        if (pos < 0 || pos >= numOfStudents)
        {
            cout << "Your position is out of range\n";
        }
        else if (name == "")
        {
            cout << "Inalid name\n";
        }
        else
        {
            numOfStudents++;
            for (int i = numOfStudents - 1; i >= pos; i--)
            {
                names[i + 1] = names[i];
            }
            names[pos] = name;
        }
    }
}
/**
 * Funtion: delStu(string name)
 * ---------------------------
 * This function deletes a student based on the student's name. If the system does not have any student or the name does not match,
 * this funtion will not allow to delete.
 * @param name The name of student's needed to delete
 */
void Students::delStu(string name)
{
    if (numOfStudents == 0)
    {
        cout << "There is no one to remove\n";
    }
    else
    {
        int position = -1;
        for (int i = 0; i < numOfStudents; i++)
        {
            if (names[i] == name)
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
            for (int i = position + 1; i <= numOfStudents; i++)
            {
                names[i - 1] = names[i];
            }
            numOfStudents--;
        }
    }
}
/**
 * Function: display()
 * ------------------
 * This function displays all current students in the system. Note that: if the name of student is an empty string, the system will ignore that
 * student.
 */
void Students::display()
{
    if (numOfStudents == 0)
    {
        cout << "There is no one in the class\n";
    }
    else
    {
        for (int i = 0; i < numOfStudents; i++)
        {
            if (names[i] != "")
            {
                cout << "The student " << i + 1 << "'s name is: " << names[i] << endl;
            }
        }
    }
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
    cout << "2. Delete a student from the system.\n";
    cout << "3. Display all students in the system\n";
    cout << "Your choice is: ";
    cin >> user;
    cin.ignore();
    if (user < 1 || user > 3)
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
void showOutput(Students &su, int user)
{
    string name;
    int position = -1;
    switch (user)
    {
    case ADD:
        cout << "Please type in the name of the student that you want to add: ";
        getline(cin, name);
        cout << "Please type in the position that you want to add: ";
        cin >> position;
        su.addStu(name, position);
        break;
    case DELETE:
        cout << "Please type in the name of the student that you want to delete: ";
        getline(cin, name);
        su.delStu(name);
        break;
    case DISPL:
        su.display();
        break;
    default:
        break;
    }
}