//
//  softwareStudent.h
//  Roster
//
//  Created by Anthony Freda on 10/15/18.
//

#ifndef softwareStudent_h
#define softwareStudent_h

#include <stdio.h>
#include "./student.h"

class SoftwareStudent : public Student {
    using Student::Student;
public:
    virtual Degree getDegreeProgram();
private:
    Degree degreeProgram = SOFTWARE;
};

#endif /* softwareStudent_h */
