#include "pqueue.h"

// constructor
pqueue::pqueue()
{  
  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() 
{
  // Does nothing
}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  // ** add the job j at the rear (and update count)
  // **   if possible else display error message. 
  if(count < MAX)
    {
      Q[count] = j;
      count++;
      trickleup(); // moves the job to the right place   
    }

  else
    {
      // display error message if array is full
      cout << "\nError: Full!!!!!" << endl;
    }
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ 
  cout << "Jobs: " ;
  // ** loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
  for(int i = 0; i <= count - 1; i++)
    {
      cout << Q[i] << " ";
    }

  cout << endl;
} 


// Utility functions follow: ------------------
void pqueue::swap(int loc1, int loc2)
{
  // temporary variable fro swapping
  int temp;

  // ** While x is > 0
  //    compare Q[x] with the parent
  //    and if the parent is bigger swap & update x
  //    to be the parent . Otherwise stop the loop.
  // (*) Call getParent to get the location of the parent
  //            based on the child's location.
  // x is loc1 and parent is loc2
  // ** swap the values in these locations in Q
  while(loc1 > 0)
    {
      loc2 = getParent(loc1);

      // if the parent is bigger swap
      if(Q[loc1] < Q[loc2])
  	{
	  // swap
	  temp = Q[loc1];
	  Q[loc1] = Q[loc2];
	  Q[loc2] = temp;
	  loc1 = loc2;
    	}
      
      else
	return;
    }
}

// Purpose: to make the very last job trickle up to the right location. Never do X--. 
void pqueue::trickleup()
{
  int parent;  // variable to hold parent of x
  int x = count - 1;  // the very last job's location
  // ** While x is > 0   
  //    compare Q[x] with the parent (*)
  //    and if the parent is bigger swap & update x 
  //    to be the parent . Otherwise stop the loop.
  // (*) Call getParent to get the location of the parent
  //            based on the child's location.
  swap(x, parent);
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{  
  // ** return the parent location based on the child loc
  int parent;  // declare a variahle to hold position of parent

  if(even(childloc))
    {
      parent = ((childloc - 2) / 2);
    }

  else
    {
      parent = ((childloc - 1) / 2);
    }

  return parent;
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if((i % 2) ==  0) 
    return true; 
  
  else 
    return false; 
}

// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify()
{ 
  int temp;    // temporary variable for swapping
  int child;       // variable for holding chlid
  int X = 0;   // the current location
  Q[0] = Q[count - 1];  // move the last job to the front
  count--;
  // ** Start X at 0 (the root)
  //    while X is within the array:
  //       Find the location of the smaller child
  //         (if the location of both children are off the tree, stop the loop).
  //       If the smaller child is smaller than the parent,
  //          swap and X becomes the smaller child's location.
  //       else no swaps so stop to loop.
  while(count - 1 > X)
    {
      child = getSmallerchild(X);
      
      if(Q[child] < Q[X])
	{
	  //swap
	  temp = Q[X];
	  Q[X] = Q[child];
	  Q[child] = temp;
	  X = child;
	}

      else
	return;
    }
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
  // ** return the location of the smaller child 
  //    Be careful because one or both of them may be
  //    beyond count-1.  Check boundaries before you 
  //    compare Q contents!!!!
  int childL, childR, smallest;

  if((2 * i) + 2 <= count - 1)
    {
      childL = (2 * i) + 1;
      childR = (2 * i) + 2;
    }

  else if((2 * i) + 1 <= count - 1)
    {
      smallest = (2 * i) + 1;
      return smallest;
    }

  else
    {
      smallest = i;
      return smallest;
    }

  if(Q[childL] > Q[childR])
    {
      smallest = childR;
    }

  else
    smallest = childL;

  return smallest;
}





