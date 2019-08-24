/*
 * Stack.h
 *
 *  Created on: Aug 23, 2019
 *      Author: eugene
 */

#ifndef STACK_H_
#define STACK_H_

#include "List.h"

template< typename STACKTYPE > class Stack : private List< STACKTYPE >
{
public:
  void push( const STACKTYPE &data )
  {
    insertAtFront( data );
  }
  bool pop( STACKTYPE &data )
  {
    return removeFromFront( data );
  }
  bool isStackEmpty() const
  {
    return isEmpty();
  }
  void printStack() const
  {
    print();
  }
};

#endif /* STACK_H_ */
