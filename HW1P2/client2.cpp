//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Daniel B. Martinez
//Complier: g++
//File type: client program client2.cpp
//=========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: To write a C++ program to generate all strings using A, B, and C as the letters. 
//Algorithm: Begin by adding the letters A, B, and C to the queue. From there a while
//           loop will be used to generate all possible strings consisting of the letters 
//           given. In the loop remove the string and then display the output. Use string
//           concatenation to add them together and continue to display and will continue 
//           to run indefinitely, eventually the queue will overflow.

int main()
{
  // Variable declaration
  queue Q;
  string letter;

  // add "A", "B", "C" in the queue
  Q.add("A");
  Q.add("B");
  Q.add("C");

  // Use 1 in the while loop -- indefinitely
  // causing an infinite loop
  while(1)
    {
      try
	{	  
	  // Remove a string and display it
	  Q.remove(letter);
	  cout << letter << endl;

	  // Add additional letter
	  Q.add(letter + "A");
	  Q.add(letter + "B");
	  Q.add(letter + "C");

	} // end try

      // Catch exceptions and report problems and quit the program now(exit(1)).
      // Error messages describe what is wrong with the expression.
      catch(queue::Overflow)
	{
	  cerr << "\nOverflow!!! Cannot Add...\n\n";
	  exit(1);
	}

      catch(queue::Underflow)
        {
          cerr << "\nUnderflow!!! Cannot Remove...\n\n";
	  exit(1);
        }

    } // end while loop
} // end program

