#ifndef LIST_H
#define LIST_H

#include "Listnode.h"
#include <iostream>
using namespace std;

template< typename NODETYPE > class List
{
public:
  List();                   //Constructor
  ~List();                  //Destructor
  void insertAtFront( const NODETYPE & );
  void insertAtBack( const NODETYPE & );
  bool removeFromFront( NODETYPE & );
  bool removeFromBack( NODETYPE & );
  bool isEmpty() const;
  void print() const;
private:
  ListNode< NODETYPE > *firstPtr;
  ListNode< NODETYPE > *lastPtr;

  //Memory allocation service function for new node
  ListNode< NODETYPE > *getNewNode( const NODETYPE & );
};

//Default constructor
template< typename NODETYPE> List< NODETYPE >::List() : firstPtr( 0 ), lastPtr( 0 )
{
  //Empty body
}

//Destructor
template< typename NODETYPE > List< NODETYPE >::~List()
{
  if ( !isEmpty() ) 
  {
    cout << "Destroying nodes ...\n";

    ListNode< NODETYPE > *currentPtr = firstPtr;
    ListNode< NODETYPE > *tempPtr;

    while ( currentPtr != nullptr )
    {
      tempPtr = currentPtr;
      cout << "Destroying node ...\n";
      currentPtr = currentPtr->nextPtr;
      delete tempPtr;
      cout << "Destroyed node.\n";
    }
  }

  cout << "All nodes destroyed\n\n";
}

//Insert a node at the beginning
template< typename NODETYPE > void List< NODETYPE >::insertAtFront( const NODETYPE &value)
{
  ListNode< NODETYPE > *newPtr = getNewNode( value );

  if ( isEmpty )
    firstPtr = lastPtr = newPtr;
  else
  {
    newPtr->nextPtr = firstPtr;
    firstPtr = newPtr;
  }
}

//Insert a node at the end
template< typename NODETYPE > void List< NODETYPE >::insertAtBack( const NODETYPE &value)
{
  ListNode< NODETYPE > *newPtr = getNewNode( value );

  if ( isEmpty )
    firstPtr = lastPtr = newPtr;
      else
      {
        lastPtr->nextPtr = newPtr;
        lastPtr = newPtr;
      }
}

//Delete a node from the beginning
template< typename NODETYPE > bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
  if ( isEmpty )
    return false;
  else
  {
    ListNode< NODETYPE > *tempPtr = firstPtr;

    if ( firstPtr == lastPtr )
      firstPtr = lastPtr = 0;
    else
      firstPtr = firstPtr->nextPtr;

    value = tempPtr->data;
    delete tempPtr;
    return true;
  }
}

//Delete a node from the end
template< typename NODETYPE > bool List< NODETYPE >::removeFromBack( NODETYPE &value)
{
  if ( isEmpty )
    return false;
  else
  {
    ListNode< NODETYPE > *tempPtr = lastPtr;

    if ( firstPtr == lastPtr)
      firstPtr = lastPtr = 0;
    else
    {
      ListNode< NODETYPE > *currentPtr = firstPtr;

      //Locate penultimate  element
      while ( currentPtr->nextPtr != lastPtr)
        currentPtr = currentPtr->nextPtr;

      lastPtr = currentPtr;
      currentPtr->nextPtr = 0;
    }

    value = tempPtr->data;
    delete tempPtr;
    return true;
  }
}

//Is list empty?
template< typename NODETYPE > bool List< NODETYPE >::isEmpty() const
{
  return firstPtr == 0;
}

//Return a pointer to newly created node
template< typename NODETYPE > ListNode< NODETYPE > *List< NODETYPE >::getNewNode( const NODETYPE &value )
{
  return new ListNode< NODETYPE >( value );
}

//Output contents of the List
template< typename NODETYPE > void List< NODETYPE >::print() const
{
  if ( isEmpty )
  {
    cout << "The list is empty." << endl;
    return;
  }

  ListNode< NODETYPE > *currentPtr = firstPtr;
  cout << "The list is:\n";

  while ( currentPtr != nullptr )
  {
    cout << currentPtr->data << endl;
    currentPtr = currentPtr->nextPtr;
  }
  cout << endl;
}


#endif //LIST_H
