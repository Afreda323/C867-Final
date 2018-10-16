//
//  roster.cpp
//  Roster
//
//  Created by Anthony Freda on 10/15/18.
//

#include "roster.h"
#include "student.h"

int main() {
    int days[3] = {20,30,35};
    Student foo = Student("A1", "John", "Smith", "John1989@gm ail.com", 40, days);
    foo.print();
    return 0;
};
