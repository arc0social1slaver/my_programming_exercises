/**
 * File: matrix.h
 * -------------
 * This program declares all class and functions for taking from user a matrix 4x4 and displaying all elements in a matrix, the sum of all 
 * elements in the matrix, the sum of all elememts in each row, the sum of all elements in each column and
 * sum of all elements in each diagonal.
*/
#pragma once
#include "header.h"

void taskRunning();
/**
 * Class: Matrix
 * ------------
 * This class wraps all information the matrix 4x4
*/
class Matrix 
{
    double matrix[4][4];
public:
    void getInput();
    double sumAll();
    double sumRow(int);
    double sumColumn(int);
    double sumFirstDiag();
    double sumSecondDiag();
    void display();
};
void getInput(Matrix &, int &);