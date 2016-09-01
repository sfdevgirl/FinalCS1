//
//  Utilities.cpp
//  ch7project
//
//  Created by Shannon Smith on 4/19/16.
//  Copyright (c) 2016 Shannon Smith. All rights reserved.
//
#ifndef Zombie_hpp
#define Zombie_hpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Utilities.hpp"

using namespace std;


//function logic
void clearCin(void){
    cin.clear();
    cin.ignore(32768, '\n');
}//clearCin


string inputString(string prompt, int minNum, int maxNum){
    
    string s_toReturn;
    
    while(true){
        cout << prompt;
        getline(cin, s_toReturn);
        
        
        if (s_toReturn.length() <= maxNum && s_toReturn.length() >= minNum){
            break;
        }//if
        else{
            cout << "*** Error, incorrect number of characters. ***\n";
            continue;
        }//else
    }//while first
    
    
    return s_toReturn;
}//string Prompt



//int

int enterInt(string prompt, int i_minNum, int i_maxNum){
    
    
    int i_toReturn;
    
    cout << prompt;
    while(true){
        
        cin >> i_toReturn;
        clearCin();
        
        
        //        if(cin.peek() != '\n'){
        //                i_toReturn = i_maxNum + 1;
        ////            clearCin();
        //        }
        //
        if(i_toReturn <= i_maxNum && i_toReturn >= i_minNum){
            break;
        }//if
        else {
            cout << "*** Error, invalid number ***\n";
            continue;
        }//else
    }//while1
    
    
    return i_toReturn;
    
    
}
//enter int
//double
double enterDouble(string prompt, double d_minNum, double d_maxNum){
    
    double d_grade;
    
    
    
    while (true) {
        cout << prompt;
        cin >> d_grade;
        
        if(cin.peek() != '\n'){
            d_grade = d_maxNum + 1;
            clearCin();
        }//if
        else if(d_grade <= d_maxNum && d_grade >= d_minNum){
            break;
        }//else if
        else {
            cout << "*** Error, invalid number ***\n";
            continue;
        }//else
    }//while1
    
    
    return d_grade;
}//double


bool fileExists(string fileName){
    ifstream inputFile;
    inputFile.open(fileName.c_str());//check if exists
    
    if(inputFile.fail()){ //if exisits
        return false;
        
    }//if
    else{
        inputFile.close(); //close
        return true;
    }
}//file Exists

void removeSpaces(char cString1[], char cString2[]){
    
    int ctr1 = 0;
    int ctr2 = 0;
    const char NULL_END = '\0';
    
    
    while (cString1[ctr1] != NULL_END) {
        if (cString1[ctr1] == ' ') {
            ctr1++;
        }//if
        
        else {
            cString2[ctr2] = cString1[ctr1];
            ctr1++;
            ctr2++;
        }//else
        
    }//while
    
    cString2[ctr2] = NULL_END;
}//removeSpaces

void writeFile(fstream &aFile){
    
    string aString;
    while (true) {
        aString = inputString("enter a string to go into file (-999 to exit) ", 1, 3000);
        if (aString == "-999") {
            break;
        }//if
        else{
            aFile.open("stuff.txt" , (ios::out | ios::app));
            aFile << aString << endl;
            
            if(aFile.fail()){
                cout << "File error on write.\n";
                //TBD: give user ability to save elsewhere...
            }//if
            else{}
            
            aFile.close();
            if(aFile.fail()){
                cout << "Failed to close the file\n";
              
            }//if
            else{}
        }//else
    }//while
    
};//writeFile

void readFile(fstream &aFile){
    string aString;
    
    aFile.open("stuff.txt" , ios::in );
    
    cout << endl << "========" << endl;
   
    if(aFile.is_open()){
        while (!aFile.eof()) {
            getline(aFile, aString);
            
            if(aFile.fail()){
                cout << "Error reading file\n";
            }//if
            else {
                cout << aString << endl;
            }//else
        }//while
    }//if
    else{}
    aFile.close();
    
};//readFile

void writeFileBi(fstream &aFile){
    int anInt =0;
    double aDouble=0.0;
    while (true) {
        anInt = enterInt("enter an integer to go into file (0 to exit) ", 0, 3000);
        if (anInt == 0) {
            break;
        }//if
        else{
            aFile.open("stuff.bin" , (ios::out| ios::binary));
            
      
            
            if(aFile.fail()){
                cout << "File error on write.\n";
                //TBD: give user ability to save elsewhere...
            }//if
            else{
                  aFile.write(reinterpret_cast<char *>(&anInt), sizeof(anInt));
            }
            
            aFile.close();
            if(aFile.fail()){
                cout << "Failed to close the file\n";
                
            }//if
            else{}
        }//else
    }//while
};

void readFileBi(fstream &aFile){
    int anInt = 0;
    double aDouble=0.0;
    
    aFile.open("stuff.bin" , ios::in | ios::binary);
    
    cout << endl << "========" << endl;
    
    if(aFile.is_open()){
        while (!aFile.eof()) {
            
            aFile.read(reinterpret_cast<char *>(&anInt), sizeof(anInt));//STUDENTS
            
            if(aFile.fail()){
                cout << "Error reading file\n";
            }//if
            else {
                cout << anInt << endl;
            }//else
            
        }//while
    }//if
    else{}
    aFile.close();
};//bin

char inputChar(string prompt, char arg1, char arg2){
    
    char returnChar;
    
    while(true){
        cout << prompt;
        cin.get(returnChar);
        
        returnChar = toupper(returnChar);
        
        if (returnChar != toupper(arg1) || returnChar != toupper(arg2)){
            break;
        }//if
        else{
            cout << "*** Error, incorrect number of characters. ***\n";
            continue;
        }//else
    }//while first
    
    
    return returnChar;
}//string Prompt

bool areYouSure(){
    
    char userResponce = ' ';
    bool tempBool = true;
    bool responceBool = true;
    
   
    
    while (tempBool) {
         cout << "Are you sure you want to do this?\n";
        cin.get(userResponce);
        clearCin();
        userResponce = toupper(userResponce);
        
        
        if (userResponce == 'Y') {
            responceBool = true;
            tempBool = false;
            break;
        }
        else if(userResponce == 'N'){
            responceBool = false;
            tempBool = false;
        }
        else{
            cout << "Invalid entry! Must be 'Y' or 'N'\n";
            continue;
        }//else
    }//while
    return responceBool;
}//areyousure







#endif
