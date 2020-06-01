//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.

//======================================================
// HW#: HW6 dgraph
// Name: Daniel B. Martinez
// File Type: dgraph.h
//========================================================
using namespace std;
#include "dgraph.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// initialize vertexName(blank) and visit numbers(0) 
dgraph::dgraph()
{
  for(int i = 0; i < SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }

  // initialize countUsed to be 0
  countUsed = 0;
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
  // the constructor and destrcutor gets called
}

void dgraph::fillTable()  // be sure to read from a specified file
{
  // variables
  string fname;
  char x;
  
  cout << "\nEnter a file name: ";
  cin >> fname;
  ifstream fin(fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help
  while(fin >> Gtable[countUsed].vertexName)  // IF I CAN READ THE NAME
    { 
      fin >> Gtable[countUsed].outDegree;

      //Then for the OutDegree times (for-loop):
      for(int i = 0; i < Gtable[countUsed].outDegree; i++)
	{
	  fin >> x;
	  (Gtable[countUsed].adjacentOnes).addRear(x);   // this is a slist function from HW3
        }
  
      // update
      countUsed++;
    }

  fin.close();
}

void dgraph::displayGraph() // be sure to display
{
  // display graph
  cout << "\n  Out Visit\tAdj\n";
  cout << " ----------------------\n";

  // in a really nice table format -- all columns but no unused rows 
  for(int i = 0; i < countUsed; i++)
    {
      cout << Gtable[i].vertexName << "  " << Gtable[i].outDegree;
      cout << " \t" << Gtable[i].visit << "\t";
      (Gtable[i].adjacentOnes).displayAll();
    }
}

int dgraph::findOutDegree(char V)// throws exception
{
  
  // does not use a loop
  int index = V - 65;

  if(index < countUsed && index >= 0)
    return Gtable[index].outDegree;
  
  throw BadVertex();
}

slist dgraph::findAdjacency(char V)// throws exception
{
  
  // does not use a loop
  int index = V - 65;

  if(index < countUsed && index >= 0)
    return Gtable[index].adjacentOnes;

  throw BadVertex();
}
