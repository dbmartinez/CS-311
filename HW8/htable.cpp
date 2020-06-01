using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
{
  // does nothing
}

htable::~htable()
{
  // does nothing
}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{ 
  return key % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element)
{
  // local variable
  int slot;

  // hash with the key part
  slot = hash(element.key);

  // add the element to a slist in the slot
  table[slot].addRear(element);

  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{
  el_t E;
  int slot = hash(skey); // hash with skey
  el_t selement;  // this is the element to look for in slist
  
  // initialize selement with just the skey
  selement.key = skey;

  // call slist's search2 with selement which returns the found element
  E = table[slot].search2(selement);
  
  // return the found element from here (it could be blank)
  return E;
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  // use loop to display
  for(int i = 0; i < 37; i++)
    { 
      cout << i << ": " ;   
      
      // call slist's displayAll
      table[i].displayAll();
    }
}
