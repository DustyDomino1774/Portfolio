//
//  utilities.h
//  CPPUtilities
//
//  Created by Bill Komanetsky on 1/29/15.
//  Copyright (c) 2015 Bill Komanetsky. All rights reserved.
//

#ifndef __CPPUtilities__utilities__
#define __CPPUtilities__utilities__

#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

class utilities
{
public:



//
//Prototypes for utilities.cpp
//
static string makeUpperCase(string);
static string makeLowerCase(string);
static void clearCIN(void);
static string inputString(string, unsigned int, unsigned int);
static int inputInt(string, int, int, int);
static double inputDouble(string, double, double, double);
float inputFloat(string promptString, float minValue, float maxValue, float exitValue);
static string centerString(string, int);
static int getRandomInt(int, int);
static double getRandomDouble(int, int, int);
static float getRandomFloat(int, int, int);
static bool verifyAction(string);
static char askOverWrite(void);
static string getRandomString(int, int);
};

#endif /* defined(__CPPUtilities__utilities__) */
