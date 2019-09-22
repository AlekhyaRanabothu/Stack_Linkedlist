#ifndef _SLLStack_
#define _SLLStack_

#include "Lnode.h"
#include "Employee.h"
class SLLStack

// This implementation of a Singly Linked List based Stack.
{
public:

    SLLStack ();
    // Initialize a new stack so that it is empty.
    SLLStack (const SLLStack &s);
    // The copy constructor (performs initialization).

   ~SLLStack ();
    // Perform actions needed when stack goes out of scope.

    bool push (const Employee &new_item);
    // Place a new item on head of the stack.
       bool pop (Employee &item);
    // Remove and return the head stack item. Check if stack is empty.
    bool headtop (Employee &item) const;
    // Return head stack item without removing it.

    // = Check boundary conditions for Stack operations.
    bool is_empty() const;
    // Returns true if the stack is empty, otherwise returns false.

    int size() const;
    // Returns the number of elements in the stack.

    void print() const;
    //Print all the elements in the stack onto the screen.
    void print(int n) const;
    // Print n elements from the stack
    void deletestack();
    //delete the stack explicitly

    int operator == (const SLLStack &s) const;
    // Checks for Stack equality.

private:
    Lnode *head;
// The head of the Linked List based Stack.
    int num;
//the number of elements in the stack.

};

#endif
