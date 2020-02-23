using namespace std;
#include <iostream>
#include <cmath>

// Purpose: To see how the binary search algorithm can be
//          used for recursion.
// Algorithm: The user will enter a number and a recursive 
//            binary search algorithm will be used to det-
//            ermine whether or not the number is in the 
//            array. If not display that it isn't in the
//            array.
// x is what we are looking for in L; first and last are slot numbers
int binarySearch(int L[], int x, int first, int last)
{
  int middle;    // Mid point of search

  // Compare with the middle entry
  middle = floor((first + last) / 2);

  cout << "comparing against an element in slot " << middle << endl;
  
  // found x at location middle, so return the location
  if(x == L[middle])
    return middle;

  // note that if first == last, there is only one element left
  else if(first == last)
    return -1;

  // go to first half              
  else if(x < L[middle])
    last = middle - 1;

  // go to second half
  else if(x > L[middle])
    first = middle + 1;

  // recursive call
  return binarySearch(L, x, first, last);
}

// main function
int main()
{ 
  int N = 10;
  int A[N];           // with N slots
  int e;              // to look for this
  int myfirst = 0;
  int mylast = N - 1; // set up initial indices
  int respos;         // result of the search

  // fixed elements for A
  A[0] = 1; 
  A[1] = 3; 
  A[2] = 5; 
  A[3] = 7; 
  A[4] = 9; 
  A[5] = 11; 
  A[6] = 13;
  A[7] = 15; 
  A[8] = 17; 
  A[9] = 19;

  cout << "\nWhat do you want to look for? ";
  cin >> e;
  cout << endl;

  // Call binarySearch here to look for e in A
  respos = binarySearch(A, e, myfirst, mylast); 

  if(respos == -1)
    cout << "\nThe number was not found" << endl; 
  
  else
    cout << "\nThe number was found in position " << respos + 1 << endl;
}
