/*
 * Queue.h
 *
 *  Created on: Aug 23, 2019
 *      Author: eugene
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "List.h"

template< typename QUEUETYPE > class Queue : private List< QUEUETYPE >
{
public:
  void enqueue( const QUEUETYPE &data )
  {
    insertAtBack( data );
  }
  bool dequeue( QUEUETYPE &data )
  {
    return removeFromFront( data );
  }
  bool isQueueEmpty() const
  {
    return isEmpty();
  }
  void printQueue() const
  {
    print();
  }
};

#endif /* QUEUE_H_ */
