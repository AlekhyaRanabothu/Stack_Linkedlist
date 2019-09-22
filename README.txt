
prerequisites for execution:

Make sure all these files exist before running the program.

1.main.cpp,Employee.cpp,Employee.h,Lnode.h,SLLStack.cpp,SLLStack.h
(Note:header files are modified.
Employee.h:Added a member function to check equality of the employees
SLLstack.h:Added a member function to delete the stack explicitly and another member function to print specified number of elements
modified function name from top to headtop and modified member variable from *top to *head).

2.Small-Database.txt(to create the stack).

3.savestack.txt to save the elements of the stack to the file.


Process for execution:

Enter the length of the stack(number of elements to be stored in the stack).
When the screen prompts for the Menu,selects the operation which you need to perform on the stack.

1.Push:Select '1' for Push.If you select push,screen prompts to enter the id,firstname and lastname you want to push to the stack.Enter the values separated by space(' ').
       prints the size of the stack and if the size of the stack is more than 5 prints the top 5 elements else prints all the elements.
2.Pop: Select '2' for Pop.If you select pop,asks the user to enter the number of elements to pop.
       If the stack size is more than the number of elements to pop,pops the specified number of elements and prints remaining elements after pop.
	   Otherwise pops all the elements from the stack.
3.Top: Select '3' for Top.This returns the top element of the stack and prints remaining elements other than top element.
4.Print:Select '4' for Printing all the elements in the stack.
5.Save: Select '5' for saving the contents of the stack to a file('savestack.txt).
6.Equality of stacks:Select'6' for checking if two stacks are equal.two stacks are created stack3 is the  copy of stack1 and the stack2 is having the same size of stack1 but have different element.
                      When you select this option,the equality is checked for stack1 and stack3 and displays the result as "stack1 and stack3 are equal"
					  the equalityfor stack2 and stack3 is checked and displays the result as "stack2 and stack3 are not equal".	
7.Quit: Select '7' for deleting the elements of the stack to make sure there is no memory leak and exits from the execution.

