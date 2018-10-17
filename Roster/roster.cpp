//
//  roster.cpp
//  Roster
//
//  Created by Anthony Freda on 10/15/18.
//

#include <iostream>
#include <sstream>
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Anthony,Freda,anthonyfreda323@gmail.com,23,10,15,20,SOFTWARE"
};

int main() {
    Roster roster;
    Degree degree;
    
    for (int i = 0; i < sizeof(studentData)/ sizeof(studentData[i]); i++) {
        string value;
        string data[9];
        string place = studentData[i];
        istringstream ss(place);
        
        int index = 0;
        while (getline(ss, value, ',')) {
            data[index] = value;
            index += 1;
        }
        
        if (data[8] == "SECURITY")
            degree = SECURITY;
        else if (data[8] == "SOFTWARE")
            degree = SOFTWARE;
        else
            degree = NETWORK;
        
        cout << data[4] << " " << data[5] << " " << data[6] << " " << data[7] << endl;
        
        roster.add(data[0], data[1], data[2], data[3],
                   stoi(data[4]), stoi(data[5]), stoi(data[6]),
                   stoi(data[7]), degree);
    }
    
    roster.printAll();
    
    return 0;
};

void Roster::add(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, Degree degree) {
    
    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] == nullptr) {
            switch (degree) {
                case SECURITY:
                    classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, days, degree);
                    break;
                case SOFTWARE:
                    classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, days, degree);
                    break;
                case NETWORK:
                    classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, days, degree);
                    break;
                default:
                    break;
            }
            break;
        }
    }
    
};

void Roster::remove(string studentID) {
    
};

void Roster::printAll() {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        classRosterArray[i]->print();
        cout << endl;
    }
};

void Roster::printDaysInCourse(string studentID) {
    
};

void Roster::printInvalidEmails() {
    
};

void Roster::printByDegreeProgram(int degreeProgram) {
    
};

Roster::~Roster() {
    
};
