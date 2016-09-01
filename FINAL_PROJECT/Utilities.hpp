//
// Utilities.hpp
//  6project2
//
//  Created by Shannon Smith on 4/2/16.
//  Copyright (c) 2016 Shannon Smith. All rights reserved.
//
#ifndef Zombie_hpp
#define Zombie_hpp

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//prototypes
void clearCin(void);

string inputString(string , int , int );

int enterInt(string , int, int);

double enterDouble(string , double , double );

bool fileExists(string );

void removeSpaces(char [], char []);

void writeFile(fstream &);

void readFile(fstream &);

void writeFileBi(fstream &aFile);

void readFileBi(fstream &aFile);

char inputChar(string, char, char);

bool areYouSure();



#endif
