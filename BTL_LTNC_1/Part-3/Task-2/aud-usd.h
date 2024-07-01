/**
 * File: aud-usd.h
 * --------------
 * This program declares all functions for asking for user input for the amount of money in VND and displaying the converted concurrency
 * on the console based on the user's choice
 */
#pragma once
#include "header.h"
#define VND_PER_USD 0.000041
#define VND_PER_AUD 0.000062

// Assign each concurrency for ease of review
enum concurrency
{
    AUD = 1,
    USD = 2
};

void taskRunning();
void getInput(double &, double &, int &, int &);
double converter(double, int);
void showOutput(double, double, int);