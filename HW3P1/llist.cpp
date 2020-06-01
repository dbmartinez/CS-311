using namespace std;
#include<iostream>
#include"llist.h" 

// Constructor
llist::llist()
{ 
  cout << "... in llist constructor..." << endl; 
  
  Front = Rear = NULL;
  Count = 0;
}

// Destructor
llist::~llist()
{ 
  cout << ".... in llist destructor..." << endl; 

  el_t temp;

  // Call deleteFront repeatedly to delete all nodes
  while(!isEmpty())
    {
      deleteFront(temp);
    }
}

// PURPOSE: Check if the list is empty by checking if both front and rear are NULL and that Count = 0.
// PARAMETER:  Checks that front and rear are null and that count is 0. return true if all params are met.
bool llist::isEmpty() 
{
  if(Front == NULL && Rear == NULL && Count == 0)
    {
      return true;
    }

  else
    {
      return false;
    }

} // be sure to check all 3 data members

// PURPOSE: Display all the elements in all the nodes.
// PARAMETER: First check if the list is empty, if not, make a temporary pointer at front, and while it doesn't
//            point to NULL, display the element in the node.
void llist::displayAll() 
{
  Node *temp = Front;

  // If empty display empty
  if(isEmpty())
    {
      cout << "[ Empty ]\n";
    }

  else
    {
      cout << "[";

      while(temp != NULL)
	{
	  cout << " " << temp->Elem << " "; 
	  temp = temp->Next;
	}
      
      cout << "]" << endl;
    }

}  // be sure to display horizontally in [  ] with
   // blanks between elements
  
// PURPOSE: Add a new node with the element to the rear of the list.
// PARAMETER: The new element that we want to add to the rear of the list.
void llist::addRear(el_t NewNum) 
{ 
  // Speical Case: Create a new node and make Front and Rear point to it. Put NewNum in  
  //               the Elem field of this new node. Count is updated.
  if(Front == NULL)
    {
      Front = new Node;
      Rear = Front;
      Rear->Elem = NewNum;
      Count++;
    }

  // Regular Case: Add a new node at the rear and puts NewNum in the Elem field
  //               of this new node. Count is updated.
  else
    {
      Rear->Next = new Node;
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;
    }

} // comment the 2 cases

// PURPOSE: Add an element to the front of the list
// PARAMETER:  the element that we will add to the front of the list:
void llist::addFront(el_t NewNum) 
{
  // Special Case: Create a new node and make Front and Rear point to it. Put NewNum in the Elem field 
  //         of this new node. Count is updated.
  if(Front == NULL)
    {
      Front = new Node;
      Rear = Front;
      Front->Elem = NewNum;
      Front->Next = NULL;
      Count++;
    }

  // Regular Case: Add a new node at the front and puts NewNum in the Elem field 
  //         of this new node. Count is updated. 
  else
    {
      Node *P = new Node;
      P->Next = Front;
      Front = P;
      Front->Elem = NewNum;
      Count++;
    }

} // comment the 2 cases

// PURPOSE: Delete the front node and elem
// PARAMETER: The variable we will be passing the old elem to that will be deleted.
void llist::deleteFront(el_t& OldNum) 
{ 

  // Error Case: If there is an error throw exception
  if(isEmpty())
    {
      throw Underflow();
    }

  // Special Case: If this is going to make the list empty, 
  //               give back the front node element through OldNum 
  //               (pass by reference) and also remove the front node. Count is updated.
  //               Make sure both Front and Rear both become NULL.
  else if(Count == 1)
    {
      OldNum = Front->Elem;
      delete Front;
      Front = Rear = NULL;
      Count--;
    }

  // Regular Case: Give back the front node element through OldNum (pass by reference)
  //               and also remove the front node. Count is updated.
  else
    {
      OldNum = Front->Elem;
      Node *Second = Front;
      Second = Front->Next;
      delete Front;
      Front = Second;
      Count--;
    }

} // comment the 3 cases

// PURPOSE: Delete the rear elem and pass the elem back
// PARAMETER: The variable that will receive the old elem
void llist::deleteRear(el_t& OldNum)
{
  // Error Case: If there is an error throw exception  
  if(isEmpty())
    {
      throw Underflow();
    }

  // Special Case: If this is going to make the list empty,
  //               give back the rear node element through OldNum (pass by reference)
  //               and also remove the rear node. Count is updated.
  //               Make sure both Front and Rear become NULL).
  else if(Count == 1)
    {
      OldNum = Rear->Elem;
      delete Rear;
      Front = Rear = NULL;
      Count--;
    }

  // Regular Case: Give back the rear node element through OldNum (pass by reference)
  //               and also remove the rear node. Count is updated.
  else
    {
      OldNum = Rear->Elem;
      Node *Second = Front;   
    
	while(Second->Next != Rear)
	{
	  Second = Second->Next;
	}

      delete Rear;
      Rear = Second;
      Rear->Next = NULL;
      Count--; 
    }

} // comment the 3 cases

/* harder ones follow */

// Utility Function to move a local pointer to the Ith node
void llist::moveTo(int J, Node*& temp)
{
    // moves temp J-1 times
  for(int K = 1; K < (J - 1); K++)
    { 
       temp = temp->Next;
    }
}

// PURPOSE: Delete the designated elem/node.
// PARAMETER: The node you wish deleted and the variable to receive the old elem.
void llist::deleteIth(int I, el_t& OldNum) 
{ 
  //Error cases: If I is an illegal value (i.e. > Count+1 or < 1) throw an exception. 
  if(I > Count || I < 1)
    {
      throw OutOfRange();
    }

  // Special cases: this should simply call deleteFront (I == 1) for some cases.
  else if(I == 1)
    {
      deleteFront(OldNum);
    }

  // Special cases: this should simply call deleteRear (I == Count) for some cases.
  else if(I == Count)
    {
      deleteRear(OldNum);
    }  

  else 
    {
      Node *P = Front;        // make P point to a node cell and points to front
      moveTo(I, P);           // call moveTo
      Node *Q = P->Next;      // Q points to the ith term
      P->Next = Q->Next;      // P points to the position after ith
      OldNum = Q->Elem;       // oldnum gets Q's elem
      delete Q;               // delete Q
      Count--;                // decrement count

    }
}
 // use moveTo to move local pointers. Be sure to comment to which node you are moving them.  

// PURPOSE: To add an element before the designated element
// PARAMETER: The designated elem and the variable we send the old number to
void llist::insertIth(int I, el_t newNum) 
{
  // Error Case: If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.
  if(I > Count + 1 || I < 1)  
    {
      throw OutOfRange();
    }

  // Special cases: this should simply call addFront (I == 1) for some cases.
  else if(I == 1)        
    {
      addFront(newNum);
    }

  // Special cases: this should simply call addRear (I == Count+1) for some cases.
  else if(I == Count + 1)
    {
      addRear(newNum);
    }

  else 
    {
      Node *P = Front;      // P points to a node cell and points to front
      moveTo(I, P);         // call moveTo
      Node *Q = new Node;   // Q points to a new node                            
      Q->Next = P->Next;    //moves Q pointer to the ith term                  
      P->Next = Q;          // p points to a new node that is now in front of ith        
      Q->Elem = newNum;     // Q -> elem gets NewNum
      Count++;              // increment count
    }
}  // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

// PURPOSE: Allow passing of a list by value and returning of a list by value
// PARAMETER: Sends the original data to be copied
llist::llist(const llist& Original) 
{

  //  this->'s data members need to be initialized here first
  Front = NULL; Rear = NULL; Count = 0;

  //  this-> object has to be built up by allocating new cells
  //  and copying the values from Original into each cell as we did with 
  //  operator= above. To do this,
  //copy here the (**) lines in Operator Overloading of = but note that it is Original and not OtherOne.

  el_t x;
  // First make sure this-> and OtherOne are not the same object.                                            
  // To do this, compare the pointers to the objects .                                                       
  if (&Original != this)  // if not the same                                                                 
    {
      // this-> object has to be emptied first.                                                              
      while (! this->isEmpty() )
        this->deleteRear(x);
      // this-> object has to be built up by allocating new cells with OtherOne elements (**)                 
      Node* P;                       // local pointer for OtherOne                                           
      P = Original.Front;

      while (P != NULL)              // a loop which repeats until you reach the end of OtherOne.            
        {
          this->addRear(P->Elem);    //P’s element is added to this->                                        
          P = P->Next;               // Go to the next node in OtherOne                                       
        }
    }// end of if 

    //  Nothing to return because this is a constructor.

} // use my code

// PURPOSE: For allowing the client to use = for linked list objects 
// PARAMETER: compare the pointers to the objects from the original. 
llist& llist::operator=(const llist& OtherOne) 
{
  el_t x;
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	this->deleteRear(x);  
      // this-> object has to be built up by allocating new cells with OtherOne elements (**)

      Node* P;                       // local pointer for OtherOne
      P = OtherOne.Front;

      while (P != NULL)              // a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  P = P->Next;               // Go to the next node in OtherOne   
	} 
    }// end of if
              
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.

} // use my code
