/**
 * File: calc-choice.h
 * ---------------
 * This program declares all functions needed for getting input/output and calculating the summation, subtraction, division,
multiplication of two numbers
 */
#pragma once
#include "header.h"

// Assign operations for ease of review
enum operations{ADD, SUB, MULTI, DIV};

void taskRunning();
void getInput(double &, double &, int &, int &);
void showOutput(double, double, double &, int);
void calcBasedOnChoice(double, double, double &, int);
void showBasedOnChoice(double, double, double, int);