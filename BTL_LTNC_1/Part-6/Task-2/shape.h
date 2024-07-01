/**
 * File: shape.h
 * ------------
 * This program declares all classes and fuctions for taking from user's input, calculating the area of shape of the user and displaying
 * it on the console
 */
#pragma once
#include "header.h"
#define PI 3.14159265

enum SHAPE
{
    SQUARE,
    RECTANGLE,
    CIRCLE,
    TRIANGLE
};
class shape
{
public:
    void shapeChose(int &);
    virtual void getData(int &){};
    virtual void calcArea(){};
    virtual void display(){};
};
class square : public shape
{
    float side;
    float area;

public:
    void getData(int &);
    void calcArea();
    void display();
};
class rectangle : public shape
{
    float length;
    float width;
    float area;

public:
    void getData(int &);
    void calcArea();
    void display();
};
class circle : public shape
{
    float radius;
    float area;

public:
    void getData(int &);
    void calcArea();
    void display();
};
class triangle : public shape
{
    float length1;
    float length2;
    float length3;
    float halfP;
    float area;

public:
    void getData(int &);
    void calcArea();
    void display();
};
void taskRunning();
void getInput(int &);
void showOutput(shape *&, int &);