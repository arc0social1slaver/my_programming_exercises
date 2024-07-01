/**
 * File: shape.cpp
 * --------------
 * This program specifies all classes and fuctions for taking from user's input, calculating the area of shape of the user and displaying
 * it on the console
 */
#include "shape.h"

/**
 * Function: taskRunning()
 * Usage: taskRunning();
 * ---------------------
 * This function takes from user's input, calculates the area of shape of the user and displays it on the console
*/
void taskRunning()
{
    shape *user;
    int choice = -1;
    while (true)
    {
        getInput(choice);
        if (choice == -1)
        {
            break;
        }
        user->shapeChose(choice);
        if (choice == -1)
        {
            break;
        }
        showOutput(user, choice);
        if (choice == -1)
        {
            break;
        }
    }
}
/**
 * Function: getInput(int &user)
 * Usage: getInput(choice);
 * ---------------------------
 * This function prompts the user to type in their choice (if the user types -1, the program will terminate; otherwise, the program will start)
 * @param user User's choice from the console
*/
void getInput(int &user)
{
    cout << "\t\t\t\tProgram displaying area of shape based on the user's choice\n";
    cout << "\t\t\t\t-----------------------------------------------------------\n";
    cout << "Please make a choice by typing an integer based on the following:\n";
    cout << "-1. Terminate the program\n";
    cout << "Otherwise, start the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user == -1)
    {
        cout << "The program will terminate\n";
    }
}
/**
 * Function: showOutput(shape *&shp, int &user)
 * Usage: showOutput(user, choice);
 * -------------------------------------------
 * This function gets measurement for the shape in order to calculate the area. After that, if user's input is valid, this function will
 * display on the console.
 * @param shp The shape that user chooses
 * @param user User's choice from the console
*/
void showOutput(shape *&shp, int &user)
{
    square sqr;
    rectangle rtg;
    circle crc;
    triangle trg;

    switch (user)
    {
    case SQUARE:
        shp = &sqr;
        break;
    case RECTANGLE:
        shp = &rtg;
        break;
    case CIRCLE:
        shp = &crc;
        break;
    case TRIANGLE:
        shp = &trg;
        break;
    default:
        break;
    }
    shp->getData(user);
    if (user != -1)
    {
        shp->calcArea();
        shp->display();
    }
}

/**
 * Member fucntion: shapeChose(int &user)
 * -------------------------------------
 * This function prompts the user to choose the shape
 * @param user User's choice from the console
*/
void shape::shapeChose(int &user)
{
    cout << "Please make a choice on the shape by typing an integer based on the following:\n";
    cout << "0. Square\n";
    cout << "1. Rectangle\n";
    cout << "2. Circle\n";
    cout << "3. Triangle\n";
    cout << "Otherwise, the program will terminate\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user < 0 || user > 3)
    {
        cout << "The program will terminate\n";
        user = -1;
    }
}
/**
 * Member function: getData(int &choice)
 * -------------------------------------
 * This function gets the side of the square from the user. If the user types -1 or negative value, the program will terminate
 * @param user User's choice from the console
*/
void square::getData(int &choice)
{
    float temp = 0; // variable used to store the length of side
    cout << "Please type in the length of side of your square (Note that, if the user types in -1 or negative value, the program will terminate):\n";
    cin >> temp;
    if (temp == -1 || temp < 0)
    {
        choice = -1;
        cout << "The program will terminate\n";
    }
    else
    {
        side = temp;
    }
}
/**
 * Member function: calcArea();
 * ---------------------------
 * This function calculates the area of the square
*/
void square::calcArea()
{
    area = side * side;
}
/**
 * Member function: display()
 * -------------------------
 * This function displays the area of the square on the console
*/
void square::display()
{
    cout << "The area of your square with side equals to " << side << " is: " << area << endl;
}
/**
 * Member function: getData(int &choice)
 * ------------------------------------
 * This function gets the length and width of the square from the user. If the user types -1 or negative value, the program will terminate
 * @param user User's choice from the console
*/
void rectangle::getData(int &choice)
{
    float temp = 0; // variable used to store the length of side
    cout << "Please type in the length of your rectangle (Note that, if the user types in -1 or negative value, the program will terminate):\n";
    cin >> temp;
    if (temp == -1 || temp < 0)
    {
        choice = -1;
        cout << "The program will terminate\n";
    }
    else
    {
        length = temp;
        cout << "Please type in the width of your rectangle (Note that, if the user types in -1 or negative value, the program will terminate):\n";
        cin >> temp;
        if (temp == -1 || temp < 0)
        {
            choice = -1;
            cout << "The program will terminate\n";
        }
        else
        {
            width = temp;
        }
    }
}
/**
 * Member function: calcArea()
 * --------------------------
 * This function calculates the area of the rectangle
*/
void rectangle::calcArea()
{
    area = length * width;
}
/**
 * Member function: display()
 * -------------------------
 * This function displays the area of the rectangle on the console
*/
void rectangle::display()
{
    cout << "The area of your rectangle with length equals to " << length << " and width equals to " << width << " is: " << area << endl;
}
/**
 * Member function: getData(int &choice)
 * ------------------------------------
 * This function gets the radius of the circle from the user. If the user types -1 or negative value, the program will terminate
 * @param user User's choice from the console
*/
void circle::getData(int &choice)
{
    float temp = 0; // variable used to store the length of side
    cout << "Please type in the radius of your circle (Note that, if the user types in -1 or negative value, the program will terminate):\n";
    cin >> temp;
    if (temp == -1 || temp < 0)
    {
        choice = -1;
        cout << "The program will terminate\n";
    }
    else
    {
        radius = temp;
    }
}
/**
 * Member function: calcArea()
 * --------------------------
 * This function calculates the area of the circle
*/
void circle::calcArea()
{
    area = PI * radius * radius;
}
/**
 * Member function: display()
 * -------------------------
 * This function displays the area of the circle on the console
*/
void circle::display()
{
    cout << "The area of your circle with radius equals to " << radius << " is: " << area << endl;
}
/**
 * Member function: getData(int &choice)
 * ------------------------------------
 * This function gets 3 lengths of the circle from the user. If the user types -1 or negative value, the program will terminate
 * @param user User's choice from the console
*/
void triangle::getData(int &choice)
{
    float temp = 0; // variable used to store the length of side
    cout << "Please type in the first length of your triangle (Note that, if the user types in -1 or negative value, the program will terminate):\n";
    cin >> temp;
    if (temp == -1 || temp < 0)
    {
        choice = -1;
        cout << "The program will terminate\n";
    }
    else
    {
        length1 = temp;
        cout << "Please type in the second length of your triangle (Note that, if the user types in -1 or negative value, the program will terminate):\n";
        cin >> temp;
        if (temp == -1 || temp < 0)
        {
            choice = -1;
            cout << "The program will terminate\n";
        }
        else
        {
            length2 = temp;
            cout << "Please type in the third length of your triangle (Note that, if the user types in -1 or negative value, the program will terminate):\n";
            cin >> temp;
            if (temp == -1 || temp < 0)
            {
                choice = -1;
                cout << "The program will terminate\n";
            }
            else
            {
                length3 = temp;
            }
        }
    }
}
/**
 * Member function: calcArea()
 * --------------------------
 * This function calculates the area of the triangle
*/
void triangle::calcArea()
{
    halfP = (length1 + length2 + length3) / 2;
    area = sqrt(halfP * (halfP - length1) * (halfP - length2) * (halfP - length3));
}
/**
 * Member function: display()
 * -------------------------
 * This function displays the area of the triangle on the console
*/
void triangle::display()
{
    cout << "The area of your triangle with length 1 equals to " << length1 << ", length 2 equals to " << length2 << ", length 3 equals to " << length3 << " is: " << area << endl;
}