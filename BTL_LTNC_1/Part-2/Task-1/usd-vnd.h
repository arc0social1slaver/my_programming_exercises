/**
 * File: usd-vnd.h
 * ---------------
 * This program declares all function needed for getting the value of USD from user and displaying the value of USD and VND to the console
*/
#pragma once
#include "header.h"
#define VND_PER_USD 24640

void taskRunning();
void getInput(double &,int &);
double usdToVnd(double);
void showOutput(double, double);