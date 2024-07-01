/**
 * File: calculate.h
 * ---------------
 * This program declares all functions needed for getting input/output and calculating the summation, subtraction, division, modulus,
multiplication of two numbers
 */
#pragma once
#include "header.h"

// Assign operations for ease of review
enum operations{ADD, SUB, DIV, MOD, MULTI};

void taskRunning();
void getInput(int &, int &, int &);
void showOutput(int, int, int &, double &);
void calcBasedOnChoice(int, int, int &, double &, int);
void showBasedOnChoice(int, int, int, double, int);