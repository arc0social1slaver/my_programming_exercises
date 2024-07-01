/**
 * File: triple.h
 * -------------
 * This program declares all class and functions for taking for user three numbers, calculating sumTripple, mulTripple, aveTriple and
 * displaying on the console
*/
#pragma once
#include "header.h"

void taskRunning();
void getInput(float &, float &, float &, int &);
float sumTripple(float, float, float);
float mulTripple(float, float, float);
float aveTripple(float, float, float);
void showOutput(float, float, float);