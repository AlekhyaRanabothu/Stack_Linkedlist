#include <cstdlib>
#include <string>
#include <iostream>
#include "Employee.h"
#include "SLLStack.h"
#include "Lnode.h"

using namespace std;

SLLStack::SLLStack() {// Initialize a new stack so that it is empty.
    head = nullptr;
    num = 0;
}
SLLStack::~SLLStack(){// destructor,Perform actions needed when stack goes out of scope.
    while(head!=nullptr){
        Lnode* tmp = head;
        head = head->next;
        delete tmp;
    }
    cout << "destructor is called and stack is deleted " << endl;
}

void SLLStack::deletestack(){// delete the stack explicitly

    while(head!=nullptr){
        Lnode* tmp = head;
        head = head->next;
        delete tmp;
    }
    cout << "stack is deleted " << endl;

}
SLLStack::SLLStack(const SLLStack &s) {// The copy constructor (performs initialization).
    head = nullptr;
    if(!s.is_empty())
    {
        Lnode* newnode = s.head;
        head = newnode;
        Lnode* newnode1 = new Lnode(Employee());
        newnode1 = s.head->next;
        while(newnode1 != nullptr)
        {
            newnode->next = new Lnode(newnode1->NewEmployee);
            newnode = newnode->next;
            newnode1 = newnode1->next;
        }

    }
}

bool SLLStack::push(const Employee &new_item) {// Place a new item on head of the stack.
    Lnode *newnode = new Lnode(new_item);
    newnode->next = head;
    head = newnode;
    num = num + 1;
    return true;
}



bool SLLStack::pop(Employee &item) {// Remove and return the head stack item. Check if stack is empty.
    Lnode *newnode = head;
    if (head == nullptr) {
        cout << "The stack is empty" << endl;
        return false;
    }
    item = head->NewEmployee;

    head = head->next;
    delete (newnode);
    num--;
    return true;
}

bool SLLStack:: headtop (Employee &item) const {// Return head stack item without removing it.
    Lnode* newnode = head;
    if (head == nullptr) {
        cout << "The stack is empty" << endl;
        return false;
    }
    item = head->NewEmployee;
    cout << "top element is" << item << endl;
}

int SLLStack::size() const// Returns the number of elements in the stack.
{
    Lnode* n = head;
   int count = 0;
    while (n!= nullptr)
    {
        ++count;
        n = n->next;
    }
    //num = count;
    return count;
}

bool SLLStack::is_empty() const {// Returns true if the stack is empty, otherwise returns false.
    if (num == 0)
        return true;
    else
        return false;

}

void SLLStack::print() const {//Print all the elements in the stack onto the screen.
    if (!is_empty()) {
        cout << "number of elements in the stack : " << size() << endl;
        Lnode *newnode = head;
        while (newnode != nullptr) {
                cout << newnode->NewEmployee;
                newnode = newnode->next;
            }
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }


void SLLStack::print(int n) const// Print n elements from the stack
{
    if (!is_empty()) {
        cout << "number of elements in the stack : " << size() << endl;
        Lnode *newnode = head;
        for (int i = 1; i <= n; i++) {
            cout << newnode->NewEmployee;
            newnode = newnode->next;
        }
    }
        else
        {
        cout << "the stack is empty" << endl;
        }
    }

int SLLStack::operator == (const SLLStack &s) const// Checks for Stack equality.
{
    Lnode* newnode = new Lnode(head->NewEmployee);
    Lnode* newnode1 = new Lnode(s.head->NewEmployee);
    newnode = head;
    newnode1 = s.head;
    

if(size() != s.size())//checks if the size of the stacks are equal
{
    cout << "stacks size is not equal"<< endl;
    return 0;
}
else//checks if all the records of the stack are equal
    if(newnode == nullptr && newnode1 == nullptr)
    {
        cout << "stacks are not equal" << endl;
        return 0;
    }
    else
        while(newnode1 != nullptr)
        {
            if(newnode->NewEmployee == newnode1->NewEmployee)
            {
                newnode = newnode->next;
                newnode1 = newnode1->next;
            }
            else
                return 0;
        }
        return 1;
}
