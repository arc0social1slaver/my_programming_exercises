/**
 * File: guess.h
 * -------------
 * This program declares all functions needed for guessing the secret number
*/
#pragma once
#include "header.h"
#define SECRET_NUM 9

void taskRunning();
void getInput(int &);
void guessProc(int &);