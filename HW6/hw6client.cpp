#include "dgraph.h"
#include <cstdlib>
#include <iomanip>
using namespace std;

// Main program
int main()
{
  el_t ans;
  slist l1;

  // 0.Declare table object
  dgraph TableObj;
  // 1.fillTable()
  TableObj.fillTable(); 
  // 2.displayGraph()
  TableObj.displayGraph();
  
  /*
  while (the user does not want to stop)
    a.the user will specify which vertex     
    b.findOutDegree of the vertex and display the result
    b.findAdjacency of the vertex and display the result (see Hint)
    c.catch exception to display error mesg but do not exit*/

  do
    {
      // ask for vertex from user
      cout << "\nEnter a vertex to find out its degree (Enter 0 to stop)\n";
      cin >> ans;
      
      if(ans != '0')
	{
	  // the user has entered a vertex, try to find it
	  try
	    {
	      cout << "Degree: " << TableObj.findOutDegree(toupper(ans)) << endl;
	    }
	  
      // invalid vertex was entered, let user know
      catch(dgraph::BadVertex)
	{
	  cerr << "Invalid Vertex\n";}
	}
      
    }while(ans != '0');      // as long as '0' was not entered


  do
    {
      // ask for vertex from user
      cout << "\nEnter a vertex to see vertex adjacency (Enter 0 to stop)\n";
      cin >> ans;

      if(ans != '0')
	{
	  // the user has entered a vertex, try to find it
	  try
	    {
	      cout << "Adjacent one(s): \n";

	      // store the list in l1 when returned
	      l1 = TableObj.findAdjacency(ans);
	      l1.displayAll();

	    }   // display the ajacent ones list
      
	  // invalid vertex was entered
	  catch(dgraph::BadVertex)
	    {
	      cerr << "Invalid Vertex\n";}
	}
      
    }while(ans != '0');       // as long as '0' was not entered
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
