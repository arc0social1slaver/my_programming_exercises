/**
 * File: volume.h
 * --------------
 * This program declares all functions needed for getting the radius, height of a cylinder, calculating its volume and displaying the volume
 * on the console
*/
#pragma once
#include "header.h"
#define PI 3.14159265

void taskRunning();
void getInput(double &, double &, int &);
double getVolume(double, double);
void showOutput(double, double, double);