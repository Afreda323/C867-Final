//
//  student.h
//  Roster
//
//  Created by Anthony Freda on 10/15/18.
//

#ifndef student_h
#define student_h

#include <stdio.h>
#include <string>
#include "./degree.h"

using namespace std;

class Student {
    
private:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3];
    Degree degreeProgram;
    
public:
    Student(string, string, string, string, int, int days[3], Degree);
    ~Student();
    
    void setStudentId(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmailAddress(string);
    void setAge(int);
    void setDaysToComplete(int*);
    void setDegreeProgram(Degree);
    
    string getStudentId() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    const int *getDaysToComplete() const;
    
    virtual Degree getDegreeProgram();
    virtual void print();
    
};

#endif /* student_h */
