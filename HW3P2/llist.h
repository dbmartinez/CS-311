//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Daniel B. Martinez
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // Check to see if empty
  bool isEmpty();
    
  // Display linked list
  void displayAll();

  //PURPOSE: creates a node and adds it to the front of the list
  //PARAMETER: the value of the node to be added
  void addFront(el_t);
    
  //PURPOSE: creates a node and adds it to the rear of the list
  //PARAMETERS: the value of the node to be added
  void addRear(el_t);

  //PURPOSE: deletes the frist element of the list
  //PARAMETERS: the value that is removed
  void deleteFront(el_t&);
    
  //PURPOSE: deletes the last element of the list
  //PARAMETERS: the value that is removed
  void deleteRear(el_t&);
    
  //PURPOSE: deletes the Ith element (Ith = user input)
  //PARAMETERS: the value that is removed
  void deleteIth(int, el_t&);  // calls moveTo

  // PURPOSE: to add an element before the designated element
  // PARAMETERS: the designated elem and the variable we send the old number to
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 
};
