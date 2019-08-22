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




#endif //LIST_H
