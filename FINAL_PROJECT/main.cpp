//*****************
//Project Name: Chapter 12, Project #1
//Project Description: Student Grades - Structure
//Project Author: Smith, Shannon
//Is this an extra credit Project:  No, but extra credit portion is complete
//Date completed: 05/12/2016,
//Operating system used: OSX
//IDE Used:  Xcode

//*****************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Utilities.hpp"

using namespace std;

//GLOBAL
const int MAX_ARRAY_SIZE = 100;


//enum

enum College {
    BRK,//0: BRK
    CSC,//1: CSC
    LPC,//2: LPC
    SFO,//3: SFO
    SLU,//4: SLU
    WASHU//5: WASHU
};//College

enum Major{
    ASTR,//0: ASTR
    BUIS,//1: BUIS
    CIS,//2: CIS
    CS,//3: CS
    ENG,//4: ENG
    MTH,//5: MTH
    MUS,//6: MUS
    PHY,//7: PHY
    VIT,//8: VIT
};//Major

struct Student{
    int i_studentID;
    string s_firstName;
    string s_lastName;
    College c_collegeAttending;
    Major m_targetMajor;
    int i_totalGrades;
    double studentGrades[100];
    
    
};//student

struct cStudent{
    int studentID;
    char FName[24];
    char LNamechar[32];
    College CollegeAttending;
    Major TargetMajor;
    int totalGrades;
    double studentGrades[100];
    
};//cStudent

string collegeToString(College);
string majorToString(Major);
void writeStudents(vector<Student>);
void readStudents(vector<Student>&);



//main program
int main(int argc, const char * argv[]) {
    
    
    //constants
    
    const double d_MAXGRADE = 100.0;
    const double d_AGRADE = 90.0;
    const double d_BGRADE = 80.0;
    const double d_CGRADE = 70.0;
    const double d_DGRADE = 60.0;
    const double d_FGRADE = 0.0;
    //    const int i_DIVISIONBY = 4;
    //    const double d_MAX_LAST_NAME = 20;
    const double d_MAX_FIRST_NAME = 12;
    const double d_MAX_ID = 12;
    const int i_MAX_ID = 90000000;
    const int i_MIN_INPUT_LENGTH = 0;
    //    const double d_MAX_PERCENT = 100;
    //    const double d_MIN_PERCENT = 0;
    const double d_MIN_INPUT_LENGTH = 0;
    
    //variables
    string s_studentID;
    string s_firstName;
    string s_lastName;
    string s_newStudentAnswer = "Y";
    string s_fullName;
    ofstream outputFile;
    ifstream inputFile;
    string fileName = "studata.bin";
    string someString;
    //    double d_grade1 = 0;
    //    double d_grade2 = 0;
    //    double d_grade3 =0;
    //    double d_grade4 =0;
    double d_averageGrade =-1;
    int setWidth = 8;
    int setWidthName =34;
    int setWidthID =11;
    //    char c_userChoice = ' ';
    bool b_keepGoing = true;
    char c_letterGrade = ' ';
    int userChoice = 0;
    double arrayGrades[MAX_ARRAY_SIZE] = {0};
    int totalGrades = 0;
    Student aStudent;
    int total = 0;
    int whichStuChange = 0;
    cStudent myCStudent;
    int readPosition = 0;
    fstream writeFile;
    int numStu =0;
    int fileSize =0;
    
    
    vector<Student> theStudents;
    
    
    
    //program
    
    do {
        
        cout << "\nWelcome to the Student Managment System\n";
        cout << "=======================================\n\n";
        
        //menu
        cout << "Main Menu\n";
        cout << "=========\n";
        cout << "1. Add a new Student\n";
        cout << "2. Print Student Grade Report\n";
        cout << "3. Clear Student Data\n";
        cout << "4. Write to Student File\n";
        cout << "5. Read from Student File\n";
        cout << "6. Random Read and Write of the Student File\n";
        cout << "9. Exit Program\n";
        
        
        
        
        
        userChoice = enterInt("Please enter a menu option: ", 1, 9);
        
        
        //switch
        switch (userChoice) {
            case 1 :{
                
                //COLLEGE
                cout << "\nEnter one of these majors the student is working twords: \n";
                cout << "0: ASTR\n";
                cout << "1: BUIS\n";
                cout << "2: CIS\n";
                cout << "3: CS\n";
                cout << "4: ENG\n";
                cout << "5: MTH\n";
                cout << "6: MUS\n";
                cout << "7: PHY\n";
                cout << "8: VIT\n";
                
                aStudent.m_targetMajor = static_cast<Major>(enterInt("Enter here: ", 0, 8));
                
                //MAJOR
                cout << "\nEnter one of these colleges the student is attending: \n";
                cout << "0: BRK\n";
                cout << "1: CSC\n";
                cout << "2: LPC\n";
                cout << "3: SFO\n";
                cout << "4: SLU\n";
                cout << "5: WASHU\n";
                
                aStudent.c_collegeAttending = static_cast<College> (enterInt("Enter here: ", 0, 5));
                
                
                
                
                //info
                
                aStudent.s_firstName = inputString("\nPlease enter the student's first name: ", d_MIN_INPUT_LENGTH, d_MAX_FIRST_NAME);
                aStudent.s_lastName = inputString("\nPLease enter the student's last name: ", d_MIN_INPUT_LENGTH, d_MAX_FIRST_NAME);
                aStudent.i_studentID = enterInt("\nPlease enter the student's ID: ", i_MIN_INPUT_LENGTH , i_MAX_ID);
                //for printing
                s_fullName = aStudent.s_lastName + ", " + aStudent.s_firstName;
                
                //grades
                aStudent.i_totalGrades = enterInt("\nHow many grades would you like to print: ", 0, 100);
                
                
                //for
                for( int i = 0; i < aStudent.i_totalGrades; i++){
                    
                    aStudent.studentGrades[i] =enterDouble("\nEnter grade: ",0.0, 100.0);
                }//for
                theStudents.push_back(aStudent);
                
                break;
            }// case 1
                
            case 2:{
                
                cout << setw(setWidthName) << "Student Name" << setw(setWidthID) << "ID"
                << setw(setWidth) << "College" << setw(setWidth) << "Major" << setw(setWidth)  << "Average" << setw(setWidth) << "Grade" << endl;
                
                cout << setw(setWidthName) << "============" << setw(setWidthID) << "========="
                << setw(setWidth) << "=======" << setw(setWidth) << "=====" << setw(setWidth) << "=======" << setw(setWidth) <<  "=====" << endl;
                
                
                for (int i=0; i<theStudents.size(); i++){
                    
                    //calculation
                    total = 0;
                    
                    
                    for (int j=0; j<theStudents[i].i_totalGrades; j++){
                        
                        
                        total = total + theStudents[i].studentGrades[j];
                    }//for
                    
                    
                    d_averageGrade = (total / theStudents[i].i_totalGrades);
                    
                    
                    if(d_averageGrade >= d_AGRADE && d_averageGrade <= d_MAXGRADE){
                        c_letterGrade = 'A';
                    }//if A
                    else if(d_averageGrade >= d_BGRADE && d_averageGrade <= d_MAXGRADE){
                        c_letterGrade = 'B';
                    }//else if B
                    else if (d_averageGrade >= d_CGRADE && d_averageGrade<= d_MAXGRADE){
                        c_letterGrade = 'C';
                    }//else C
                    else if (d_averageGrade >= d_DGRADE && d_averageGrade <= d_MAXGRADE){
                        c_letterGrade = 'D';
                    }//else D
                    else if (d_averageGrade >= d_FGRADE && d_averageGrade<= d_MAXGRADE){
                        c_letterGrade = 'F';
                    }//else F
                    else if (d_averageGrade == -1){
                        c_letterGrade = ' ';
                        d_averageGrade =0;
                    }
                    else{
                        cout << "*** Invalid test score entered ***\n";
                        
                    }//else
                    
                    
                    
                    s_fullName = theStudents[i].s_lastName + ", " + theStudents[i].s_firstName;
                    
                    
                    
                    cout << setw(setWidthName) << s_fullName << setw(setWidthID) << theStudents[i].i_studentID << setw(setWidth) << collegeToString(theStudents[i].c_collegeAttending) << setw(setWidth)
                    << majorToString(theStudents[i].m_targetMajor)
                    << setw(setWidth)  << d_averageGrade << setw(setWidth) << c_letterGrade << endl;
                }
                break;
            }//case 2
                
                
            case 3:{
                if (areYouSure() == true) {
                     theStudents.clear();
                    break;
                }
                else{
                    break;
                }
               
                
                
            }//case 3
                
                
                
                //Write data
            case 4:{
                
                writeStudents(theStudents);
                break;
            }//case 5
                
            case 5:{
                
                readStudents(theStudents);
                
                break;
                
            }// case5
                
            case 6:{
                
                
                
                
                
                writeFile.open("studata.bin", ios::in | ios::out | ios::binary);
                
                writeFile.seekg(0L, ios::end); //go to end
                fileSize = writeFile.tellg(); //save size of file
                numStu = (fileSize / sizeof(cStudent)); //calc number  in file
                
                whichStuChange = enterInt("Which student would you like to read?", 1, numStu);
                
                
                
                
                readPosition = (whichStuChange - 1)* sizeof(cStudent);  //calc position in file
                writeFile.seekg(readPosition, ios::beg); //move pointer to boat to read
                writeFile.read(reinterpret_cast<char *>(&myCStudent), sizeof(myCStudent));
                cout << "You chose student " << myCStudent.LNamechar << ", " << myCStudent.FName << endl; //repete name
                // write that back to file
                string tempString = inputString("What last name would you like to make this student? ", 1, 30);
                strcpy(myCStudent.LNamechar, tempString.c_str());
                
                
                
                writeFile.seekp(readPosition, ios::beg);
                writeFile.write(reinterpret_cast<char *>(&myCStudent), sizeof(myCStudent));
                writeFile.close();
                
                break;
                
            }//case 6
                
                
                //exit
            case 9:{
                cout << "\nProgam ending, have a nice day\n";
                b_keepGoing = false;
                break;
            }// case 6
                
        }//switch
        
    }//do
    while(b_keepGoing);
    return 0;
    
}//main

string collegeToString(College aStudent){
    string returnString;
    
    if (aStudent == 0) {
        returnString = "BRK";
    }
    else if (aStudent == 1) {
        returnString = "CSC";
    }
    else if (aStudent == 2) {
        returnString = "LPC";
    }
    else if (aStudent == 3) {
        returnString = "SFO";
    }
    else if (aStudent == 4) {
        returnString = "SFO";
    }
    else if (aStudent == 5) {
        returnString = "SLU";
    }
    else if (aStudent == 6) {
        returnString = "WASHU";
    }
    else {
        returnString = "error";
    }
    
    return returnString;
};

string majorToString(Major aStudent){
    string returnString;
    
    if (aStudent == 0) {
        returnString = "ASTR";
    }
    else if (aStudent == 1) {
        returnString = "BUIS";
    }
    else if (aStudent == 2) {
        returnString = "CIS";
    }
    else if (aStudent == 3) {
        returnString = "CS";
    }
    else if (aStudent == 4) {
        returnString = "ENG";
    }
    else if (aStudent == 5) {
        returnString = "MTH";
    }
    else if (aStudent == 6) {
        returnString = "MUS";
    }
    else if (aStudent == 7) {
        returnString = "PHY";
    }
    else if (aStudent == 8) {
        returnString = "VIT";
    }
    else {
        returnString = "error";
    }
    
    return returnString;
};

void writeStudents(vector<Student> theStudents){
    
    fstream writeFile;
    cStudent aCStudent;
    
    
    
    
    if (fileExists("studata.bin") == true) {
        cout << "This file exists.\n";
        
        
        if (areYouSure() == true) {
            
        }
        else{
            return;
        }
        
        
    }//if
    else {}//else
    
    
    writeFile.open("studata.bin", ios::binary | ios::out);
    
    
    for (int i = 0; i < theStudents.size(); i++) {
        
        
        
        
        aCStudent.studentID = theStudents[i].i_studentID ;
        strcpy(aCStudent.FName, theStudents[i].s_firstName.c_str());
        strcpy(aCStudent.LNamechar , theStudents[i].s_lastName.c_str());
        aCStudent.CollegeAttending = theStudents[i].c_collegeAttending;
        aCStudent.TargetMajor = theStudents[i].m_targetMajor;
        aCStudent.totalGrades = theStudents[i].i_totalGrades;
        
        for (int j = 0; j < aCStudent.totalGrades; j++) {
            
            aCStudent.studentGrades[j] = theStudents[i].studentGrades[j];
        }//for
        
        
        
        writeFile.write(reinterpret_cast<char*>(&aCStudent), sizeof(aCStudent));
        
    }//for
    writeFile.close();
    
    
    
}//write


void readStudents(vector<Student> &theStudents){
    
    Student aStudent;
    cStudent aCStudent;
    fstream writeFile;
    char userResponse= ' ';
    bool tempBool = true;
    
    if (!theStudents.empty()){
        while(tempBool){
            
            userResponse= ' ';
            cout << "This student vector is not empty. Would you like to overwrite? Y/N\n";
            cin.get(userResponse);
            userResponse = toupper(userResponse);
            
            
            if (userResponse == 'Y' ){
                theStudents.clear();
                cout << "The vector has been cleared\n";
                
                break;
            }//if
            
            else if (userResponse == 'N'){
                cout << "The vector will be appended to\n";
                
                break;
            }//else if
            else{
                cout << "Invalid entry! Must be 'Y' or 'N'\n";
                continue;
            }//else
        }//while
        
    }//if
    
    writeFile.open("studata.bin", ios::binary | ios::in);
    
    while (!writeFile.eof()) {
        
        writeFile.read(reinterpret_cast<char*>(&aCStudent), sizeof(aCStudent));
        
        if (writeFile.eof()) {
            break;
        }//
        
        
        aStudent.i_studentID = aCStudent.studentID;
        aStudent.s_firstName = aCStudent.FName;
        aStudent.s_lastName = aCStudent.LNamechar;
        aStudent.c_collegeAttending = aCStudent.CollegeAttending;
        aStudent.m_targetMajor = aCStudent.TargetMajor;
        aStudent.i_totalGrades = aCStudent.totalGrades;
        
        for (int j = 0; j < aStudent.i_totalGrades; j++) {
            aStudent.studentGrades[j] = aCStudent.studentGrades[j];
        }//for
        
        
        theStudents.push_back(aStudent);
    }//while
    
    writeFile.close();
    
    cout << "The reading is complete!\n";
    
}//read





