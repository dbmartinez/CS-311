using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them

// do not change this one
slist::slist()
{ 
  //cout << "slist constructor..." << endl;
}

/*
slist::~slist()
{
  //cout << "slist destructor..." << endl;
}*/

// positions always start at 1
int slist::search(el_t key)
{
  // temp node p and node counter
  Node *p = Front;
  int elemNum = 1;
  
  // while p isn't null, keep going 
  while(p != NULL) 
    {
      // if the node we are looking at it the key, then we can return the counter 
      if(p->Elem == key)
	{
	  return elemNum;
	}

      // continue through list and increment
      p = p->Next;
      elemNum++;          
    }

  return 0;            
}

// don't forget to throw OutOfRange for bad position
void slist::replace(el_t element, int pos)
{
  // search through the list to see if any node contains Key.
  // If so, return its position (>=1). Otherwise, return 0.
  if(pos > Count || pos < 1)
    {
      // throw exception
      throw OutOfRange();
    }

  // make a temporary node at front 
  Node *p = Front;
  int position = 1;

  // and while we aren't at the designated node, move the p
  // pointer along the list and increment position.
  while(position != pos)
    {
      p = p->Next;
      position++;
    }

  // when we reach the Node, replace the element with the new elem.
  p->Elem = element;
}

bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false
  if(this->Count != OtherOne.Count) 
    {
      return false;
    }

  // creating nodes that will be compared
  // setting both nodes to both fronts of both lists 
  Node *p = this->Front;
  Node *q = OtherOne.Front;

  // if the same lengths, check each node to see if the elements are the same 
  // since both lists have the same lenght we only need to check that one of them is not == NULL 
  while(p != NULL)
    {
      // if some elements are not equal 
      if(p->Elem != q->Elem)
	{
	  return false;
	}

      // going to the next two nodes.
      p = p->Next;
      q = q->Next;
    }

  return true;
}

// copy search and create search2
// 
el_t slist::search2(el_t key)
{
  // temp node
  Node *nodePtr = Front;

  // while p isn't null, keep going 
  while(nodePtr != NULL)
    {
      //if the node we are looking at it the key, then we can return the counter 
      if(nodePtr->Elem == key)
	{
	  return nodePtr->Elem;
	}

      // continue through list and increment
      nodePtr = nodePtr->Next;
    }

  el_t empty;
  return empty;
}
