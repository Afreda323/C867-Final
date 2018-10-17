//
//  networkStudent.h
//  Roster
//
//  Created by Anthony Freda on 10/15/18.
//

#ifndef networkStudent_h
#define networkStudent_h

#include <stdio.h>
#include "./student.h"

class NetworkStudent : public Student {
    using Student::Student;
public:
    virtual Degree getDegreeProgram();
private:
    Degree degreeProgram = NETWORK;
};

#endif /* networkStudent_h */
