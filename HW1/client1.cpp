using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: Solve postfix problem
//Algorithm: Using a while loop, check each character
// to see whether it is an integer or an operator. Add
// the integers to stack, When an operator appears,  
// remove the two integers to do the operation. Then
// place it(push) back into stack.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "\n\nType a postfix expression: ";
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  int result; // store results in variable result
  int box1;   // receive things from pop
  int box2;   // receive things from pop
  
  while(expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 
	 // ** do all the steps in the algorithm given in Notes-1

	 // 2. if it is an operand(number), push it (you might get 
	 // Overflow exception)
	 if(item >= '0' && item <= '9')
	   {
	     // Conversion of char item to an integer
	     int x = int(item) - 48;
	     postfixstack.push(x);
	   }

	 // 3. else if it is an operator, pop the two operands (you
	 // might get Underflow exception), and apply the operator to
	 // the two operands, and push the result.
	 else if(item == '-' || item == '*' || item == '+')
	   {
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);

	     if(item == '-')
	       {
		 result = box2 - box1;
	       }

	     else if(item == '*')
	       {
		 result = box2 * box1;
	       }

	     else if(item == '+')
	       {
		 result = box2 + box1;
	       }
	     
	     postfixstack.push(result);
	   }

	 // 4. else it is an invalid item(throws exception) 
	 else
	   {
	     throw "\nInvalid Item\n";
	   }	 
       } // this closes try

      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch(stack::Overflow) 
	{
	  cerr << "\nOVERFLOW!!! Expression too long...\n\n";
	  exit(1);
	}

      catch(stack::Underflow)
	{
	  cerr << "\nUNDERFLOW!!! Too few operands...\n\n";
	  exit(1);
	}

      catch(char const* errormsg ) // for invalid item case
	{
	  cerr << "\nInvalid expression...\n\n";
	  exit(1);
	}

      // go back to the loop after incrementing i
     i++;

    }// end of while
  
  // After the loop successfully completes: 
  // Pop the result and show it
  postfixstack.pop(result);

  if(postfixstack.isEmpty())
    {
      cout << "\nResult: " << result;
      cout << endl << endl;
    }

    // If anything is left on the stack, an incomplete expression 
    // was found so inform the user.
  else if(!postfixstack.isEmpty())
    {
      cout << "\nIncomplete expression...\n\n";
    }
}// end of the program
