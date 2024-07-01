/**
 * File: math-ad.h
 * ---------------
 * This program declares all function needed for taking one number from the user then calculating and displaying its abs, sin, cos, 
 * tan, log, log10, sqrt, exp
*/
#pragma once
#include "header.h"

// Assign the math function for ease of review
enum MATH_AD {ABS, SIN, COS, TAN, LOG, LOG10, SQRT, EXP};

void taskRunning();
void getInput(double &,int &);
void showOutput(double, double &);
void mathBasedOnChoice(double, double &, int);
void showBasedOnChoice(double, double, int);