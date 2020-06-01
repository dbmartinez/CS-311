#include "dgraph.h"
#include "stack.h"
#include <iostream>
using namespace std;

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  /* assignment sheet and use that has the comments. 
  Display the graph before DFS begins.
    Push A onto the stack to start.
    While the stack is not empty do:
    {
      Remove a vertex v from the stack.
	Display the vertex name.  E.G. â€œRemoved B from stackâ€
	If v is not marked yet (visit number is 0) then 
	mark it (visit it **) and inform the user E.G. â€œVisit B as 2â€
	get its adjacency list 
	if no adjacent ones inform the user E.G. â€œDeadend reached â€“ backupâ€
	  else put adjacent ones on the stack (delete from the rear and push) informing the user
	    else inform the user E.G. â€œB had been visited already - backup.â€
		   Display the stack clearly labeling it as the current stack
    }

  Display the Graph nicely with visit numbers for all vertices.*/
  
  dgraph table;              // initailaize a new graph
  slist tempList;            // holds list given from adjacent vertex function 
  stack tableStack;          // stack for holding vertex pushed from the graph
  int visitNum = 0;          // indicates the current slot in the graph
  el_t vertex;               // temporary variable to hold a vertex, either from stack or list

  // Display the graph before DFS begins
  table.fillTable();         // fill the graph
  table.displayGraph();      // display without assigned visit numbers 
  tableStack.push('A');      // start with A

  // While the stack is not empty
  while(!tableStack.isEmpty())
    {
      // remove a vertex v from the stack
      tableStack.pop(vertex);
      cout << "\nRemoved " << vertex << " from stack";

      // if v is not marked yet (visit number is 0)
      if(!table.isMarked(vertex))
	    {
        visitNum++;
        // inform the user E.G. â€œVisit B as 2â€
        cout << "\nVisit " << vertex << " as " << visitNum;

        // give the new visit num to the poped vertex 
        table.visit(visitNum, vertex);
        tempList = table.findAdjacency(vertex);

        if(tempList.isEmpty())
          {
            // find the adjacent list from popped vertex 
            cout << "\nDeadend reached - backup";
          }
	      
          else
          {
            // push the adjacent verteces until list is empty 
            while(!tempList.isEmpty())
            {
              // store rear vertex into vertex 
              tempList.deleteRear(vertex);

              cout << "\nPushing " << vertex << " into stack";

              // check if the vertex was already marked 
              if(!table.isMarked(vertex))
                 tableStack.push(vertex);
            }
          }
    }

    else
    {
      cout << endl;
      cout << vertex << " had been visited already - backup\n";
    }

   tableStack.displayAll();
   }

   table.displayGraph();
}
