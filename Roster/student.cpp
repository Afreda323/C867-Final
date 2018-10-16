//
//  student.cpp
//  Roster
//
//  Created by Anthony Freda on 10/15/18.
//

#include "student.h"
#include <string>
#include <iostream>

using namespace std;

// Constructor
Student::Student(string id, string fn, string ln, string email, int age, int days[3], Degree degree) {
    setStudentId(id);
    setFirstName(fn);
    setLastName(ln);
    setEmailAddress(email);
    setAge(age);
    setDaysToComplete(days);
    setDegreeProgram(degree);
};

Student::~Student() {};

// Setters
void Student::setStudentId(string id) {
    studentId = id;
};
void Student::setFirstName(string fn){
    firstName = fn;
};
void Student::setLastName(string ln) {
    lastName = ln;
};
void Student::setEmailAddress(string email) {
    emailAddress = email;
};
void Student::setAge(int age) {
    age = age;
};
void Student::setDaysToComplete(int *days) {
    for (int i = 0; i < 3; i++) {
        daysToComplete[i] = days[i];
    }
};
void Student::setDegreeProgram(Degree degree) {
    degreeProgram = degree;
};

// Getters
string Student::getStudentId() const {
    return studentId;
};
string Student::getFirstName() const {
    return firstName;
};
string Student::getLastName() const {
    return lastName;
};
string Student::getEmailAddress() const {
    return emailAddress;
};
int Student::getAge() const {
    return age;
};
const int * Student::getDaysToComplete() const {
    return daysToComplete;
};

Degree Student::getDegreeProgram() {
    return degreeProgram;
};

void Student::print() {
    cout << "Student ID: " << studentId << "\t"
    << "First Name: " << firstName << "\t"
    << "Last Name: " << lastName << "\t"
    << "Email Address: " << emailAddress << "\t"
    << "Age: " << age << " "
    << "Days In Course: " << daysToComplete[0] << ", "
    << daysToComplete[1] << ", " << daysToComplete[2]
    << endl;
};
