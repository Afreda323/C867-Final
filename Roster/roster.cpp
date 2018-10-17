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

//Function that checks the validity of an email address string
bool isValidEmail (string email) {
    if (email.find("@") != string::npos && email.find(".") != string::npos && email.find(" ") == string::npos) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Roster classRoster;
    Degree degree;
    
    // Loop through, parse and and student data to roster
    // based on the degree type of the student.
    for (int i = 0; i < sizeof(studentData)/ sizeof(studentData[i]); i++) {
        string value, data[9], place = studentData[i];
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
                
        classRoster.add(data[0], data[1], data[2], data[3],
                   stoi(data[4]), stoi(data[5]), stoi(data[6]),
                   stoi(data[7]), degree);
    }
    
    // Method calls based on those mentioned in rubric
    classRoster.printAll();
    classRoster.printInvalidEmails();
    
    for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
        classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
    }
    cout << endl;
    
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.remove("A3");
    classRoster.~Roster();
    
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
    bool found = false;
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
            classRosterArray[i] = nullptr;
            found = true;
            break;
        }
    }
    
    if (found == false) {
        cout << "Error Removing Student: A student with ID " << studentID << " was not found." << endl;
    } else {
        cout << studentID << " Removed." << endl;
    }
};

void Roster::printAll() {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
};

void Roster::printDaysInCourse(string studentID) {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getStudentId() == studentID) {
                const int * classes = classRosterArray[i]->getDaysToComplete();
                int average = (classes[0] + classes[1] + classes[2]) / 3;
                cout << studentID << " average: " << average << endl;
            }
        }
    }
};

void Roster::printInvalidEmails() {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] != nullptr) {
            if (!isValidEmail(classRosterArray[i]->getEmailAddress())) {
                cout << classRosterArray[i]->getStudentId()
                << " " << classRosterArray[i]->getEmailAddress()
                << endl;
            }
        }
    }
    cout << endl;
};

void Roster::printByDegreeProgram(int degreeProgram) {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
                classRosterArray[i]->print();
            }
        }
    }
    cout << endl;
};

Roster::~Roster() {
    
};
