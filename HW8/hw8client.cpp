#include "htable.h"
#include <iostream>
using namespace std;

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+name to add to the table. e.g. el_t X(30, "mary");
int main()
{ 
  // local variables
  htable hashTable;
  el_t empty;
  int inputKey = 0;
  string str = " ";
  int theKey = 0;

  // Loop: 
  // Interactively add about 20 keys and names to the table,
  // making sure some of them  collide. (function add)
  // You can create el_t containing a key and name using a constructor. 
  for(int i = 0; i < 20; i++)
    {
      cout << "Enter Key: " ;
      cin >> inputKey;
      
      cout << "Enter Name: " ;
      cin >> str;
    
      el_t elem(inputKey, str);
      hashTable.add(elem);
    }

  // DisplayTable.
  hashTable.displayTable();

  // Loop:
  // Interactively look up names using keys. (function find)
  // Cout the key + name if found else (blank element was returned)
  // an error message.
  while(theKey != -1)
    {
      cout << "Look for? " << endl;
      cin >> theKey;
        
      if(theKey != -1)
	{
	  el_t found = hashTable.find(theKey);
	  
	  if(found == empty)
	    {
	      cout << theKey <<  " not Found" << endl;
	    }
	  
	  else
	    {
	      cout << "Found: " << found <<  endl;
	    }
        }
    }
}
