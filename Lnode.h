
#ifndef _Lnode_
#define  _Lnode_

#include "Employee.h"

class Lnode {
public:
    Employee NewEmployee;
    Lnode *next;
    Lnode(Employee NewPerson) {
        NewEmployee = NewPerson;
        next = NULL;
    }
};


#endif