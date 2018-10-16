//
//  securityStudent.h
//  Roster
//
//  Created by Anthony Freda on 10/15/18.
//

#ifndef securityStudent_h
#define securityStudent_h

#include <stdio.h>
#include "./student.h"

class SecurityStudent : public Student {
    using Student::Student;
public:
    virtual Degree getDegreeProgram();
private:
    Degree degreeProgram = SECURITY;
};

#endif /* securityStudent_h */
