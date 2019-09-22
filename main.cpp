#include <cstdlib>
#include <string>
#include <iostream>
#include "SLLStack.h"
#include <fstream>

using namespace std;

int main()
{
    int stack_len;// size of the stack
    int id;//employee id
    string lastname,firstname;//employee lastname and firstname
    int op;//to select the menu
    int num_pop;// number of elements to pop from the stack
    char choice;// to check if the user wanted to continue the execution
    cout << "Enter the length of the stack"<< endl;
    cin >> stack_len;//reads the size of the stack the user want to create
    SLLStack stack1;//creates an empty stack
    cout << "empty stack is created: " << endl;
    ifstream emp_in;// input stream to read from file to stack
    ofstream emp_out;// output stream to save to file from stack
    emp_in.open("Small-Database.txt");//opens the specified file 
    if(emp_in.fail())// checks if the file can be opened
    {
        cerr << "Failed to open the file" << endl;
    }

    cout << "file is opened" << endl;

    for (int i = 1;i <= stack_len;i++)// reads the specified number of records from the file and stores in the stack
    {
        Employee NewEmployee;
        emp_in >> NewEmployee;
        stack1.push(NewEmployee);
    }
    cout << "file is read and pushed to the stack"<< endl;
    cout << " The stack created is :"  << endl;
    stack1.print();// prints the elements of the stack
    SLLStack stack2(stack1);// creates a copy of the stack1 using copy constructor(used in checking equality)
    SLLStack stack3(stack1);//creates a copy of the stack1 using copy constructor(used in checking equality)
    Employee NewEmployee;//create Employee object
    do {
        cout << "Select any number of the following operations : \n 1 for Push \n 2 for Pop \n 3 for Top \n 4 for Print \n 5 for Save \n 6 for Equality of stacks \n 7 for Quit" << endl;
        cin >> op;//reads the menu to perform operations
        switch(op) {
            case 1: cout << "you have selected Push operation" << endl;
                cout << "enter the employeeid ,firstname and lastname separated by space" << endl;
                cin >> id >> firstname >> lastname;
                stack1.push(Employee(id, lastname, firstname));//push the Employee record specified by the user onto the stack
                cout << "The number of elements in the stack are : " << endl;
                if(stack1.size()>=5)//prints top 5 elements if the stack size is greater than 5 
                {
                    cout <<"Printing the top 5 elements of the stack" << endl;
                    stack1.print(5);
                }
                else//prints all the elements if the stack size is less than 5
                {
                    cout <<"Printing all the elements of the stack" << endl;
                    stack1.print();
                }
                break;
            case 2 :
                cout << "you have selected Pop operation" << endl;
                cout << "Enter the number of elements to pop" << endl;
                cin >> num_pop;// reads the number of elements to be popped from stack from the user
                if (stack1.size()==0)// checks if the stack is empty
                {
                    cout << "stack is empty" << endl;
                }
                else if (stack1.size() >= num_pop) {// if the stack size is more than number of elements to be popped,pops the specified number of records
                    for (int k = 0; k < num_pop; k++) {
                        stack1.pop(NewEmployee);
                        cout << "popped : " << NewEmployee << endl;

                    }
                    cout << "The remaining number of elements in the stack is :" << stack1.size() << endl;
                } else {
                    for (int b = stack1.size(); b > 0; b--) {//else pops all the elements from the stack
                        stack1.pop(NewEmployee);
                        cout << " popped : " << NewEmployee << endl;
                    }

                    cout << "popped all the elements of the stack" << endl;
                }
                break;
            case 3 :
                cout << "you have selected Top operation" << endl;
                stack1.headtop(NewEmployee);//prints the top employee of the stack
                cout << "The remaining elements of the stack other than the top element are : " << stack1.size() - 1
                     << endl;
                break;
            case 4 :// prints all the elements of the stack
                cout << "you have selected Print operation" << endl;
                cout << "Printing all the elements of the stack" << endl;
                stack1.print();
                break;

            case 5 ://saves all the employees of the stack to a file on the disk
                cout << "you have selected save operation" << endl;
                emp_out.open("savestack.txt");
                if (emp_out.fail()) {
                    cerr << "Failed to open the file" << endl;
                }
                cout << "file is opened" << endl;
                cout << " the contents of the stack is" << endl;
                stack1.print();
                int p;
                p = stack1.size();
                for (int i = 0; i < p; i++) {
                    stack1.pop(NewEmployee) << '\n';
                    emp_out << NewEmployee<< endl;

                }
                cout << "the stack is saved to a file" << endl;
                break;
            case 6 :// checks if the stacks are equal
                cout << "checking if the stacks are equal" <<endl;
                stack2.pop(NewEmployee);// pops a record from the stack2 and adds a new record so that it is different from the stack1 and have the same size of stack1
                stack2.push(Employee(1, "Alekhya", "Ranabothu"));
                cout <<"The elements of stack 2 are :" << endl;
                stack2.print();//prints the stack2
                cout << "The elements of stack3 are :" <<endl;
                stack3.print();// print the stack3
                cout << "The elements of stack1 are :" <<endl;
                stack1.print();//prints the stack1
                if (stack1 == stack3)//check if the stacks are equal
                {
                    cout << "stack1 and stack3 are equal" << endl;
                }
                if(!(stack1 == stack3))
                {
                    cout << "stack1 and stack3 are not equal" << endl;
                }

                if (stack2 == stack3)// checks if the stacks are equal
                {
                    cout << "stack2 and stack3 are equal" << endl;
                }
                if(!(stack2 == stack3))
                {
                    cout << "stack2 and stack3 are not equal" << endl;
                }
                break;
            case 7 :// deletes all the stack to avoid memory leakage and quits
                cout << "You have selected quit operation " << endl;
                stack1.deletestack();
                stack2.deletestack();
                stack3.deletestack();
                cout << "cleared and deleted the stack successfully " << endl;
                break;

            default :
                cout << "no operation is selected from the menu" << endl;
                break;
        }
        if(op != 7) {// if the user selects an option other than quit,user will be prompted if he wants to continue
            cout << "Want to continue? if yes press 'y' else press 'n'" << endl;
            cin >> choice;// read from the user if he wants to continue
        }
        else
             break;
    }while(choice == 'y' || choice == 'Y'  );

    return 0;
}

