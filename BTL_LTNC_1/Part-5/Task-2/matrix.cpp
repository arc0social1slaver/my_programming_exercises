/**
 * File: matrix.cpp
 * ---------------
 * This program specifies all class and functions for taking from user a matrix 4x4 and displaying all elements in a matrix, the sum of all elememts
 * in the matrix, each row, the sum of all elements in each column and sum of all elements in each diagonal.
 */
#include "matrix.h"

void taskRunning()
{
    Matrix ma;
    int choice = -1;
    while (true)
    {
        getInput(ma, choice);
        if (choice == 0)
        {
            break;
        }
        ma.display();
    }
}

void getInput(Matrix &ma, int &user)
{
    cout << "\t\t\t\tProgram displaying the matrix and its sum of each row, column and diagonal\n";
    cout << "\t\t\t\t-------------------------------------------------------------------------\n";
    cout << "Please make a choice by typing an integer (1-10) based on the following:\n";
    cout << "1-10. Start the program\n";
    cout << "Otherwise, terminate the program\n";
    cout << "Please type a number: ";
    cin >> user;
    if (user < 1 || user > 10)
    {
        user = 0;
        cout << "The program will terminate\n";
    }
    else
    {
        ma.getInput();
    }
}

void Matrix::getInput()
{
    double num = -1; // variable that contains the value of the input
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Please type in the element in the row " << i + 1 << " and the column " << j + 1 << ":\n";
            cin >> num;
            matrix[i][j] = num;
        }
    }
}
double Matrix::sumAll()
{
    double sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}
double Matrix::sumColumn(int col)
{
    double sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += matrix[i][col];
    }
    return sum;
}
double Matrix::sumRow(int row)
{
    double sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += matrix[row][i];
    }
    return sum;
}
double Matrix::sumFirstDiag()
{
    double sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += matrix[i][i];
    }
    return sum;
}
double Matrix::sumSecondDiag()
{
    double sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += matrix[i][3 - i];
    }
    return sum;
}
void Matrix::display()
{
    cout << "Matrix that the user has inputted:\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << setw(20) << left << matrix[i][j];
        }
        cout << endl
             << setfill('-');
        cout << setw(80) << "-" << endl;
        cout << setfill(' ');
    }
    cout << "The sum of all of elements in the matrix is: " << sumAll() << endl;
    cout << setfill('-');
    cout << setw(50) << "-" << endl;
    cout << setfill(' ');
    cout << "The sum of each row is:\n";
    for (int i = 0; i < 4; i++)
    {
        string rowOp = "Row ";
        char numRow = (i + 1) + '0';
        rowOp += numRow;
        cout << setw(30) << left << rowOp;
        cout << setw(20) << left << sumRow(i) << endl;

        cout << setfill('-');
        cout << setw(50) << "-" << endl;
        cout << setfill(' ');
    }
    cout << "The sum of each column is:\n";
    for (int i = 0; i < 4; i++)
    {
        string colOp = "Column ";
        char numCol = (i + 1) + '0';
        colOp += numCol;
        cout << setw(30) << left << colOp;
        cout << setw(20) << left << sumColumn(i) << endl;

        cout << setfill('-');
        cout << setw(50) << "-" << endl;
        cout << setfill(' ');
    }
    cout << "The sum of each diagonal is:\n";
    cout << setw(30) << left << "Diagonal 1";
    cout << setw(20) << left << sumFirstDiag() << endl;
    cout << setfill('-');
    cout << setw(50) << "-" << endl;
    cout << setfill(' ');
    cout << setw(30) << left << "Diagonal 2";
    cout << setw(20) << left << sumSecondDiag() << endl;
    cout << setfill('-');
    cout << setw(50) << "-" << endl;
    cout << setfill(' ');
}