#ifndef LISTNODE_H
#define LISTNODE_H

//Leading declaration of class List is necessary in order to use this class in friend directive below

template< typename NODETYPE > class List;

template< typename NODETYPE > class ListNode
{
  friend class List< NODETYPE >;        //Make List to be friend of ListNode

public:
  ListNode(const NODETYPE & );          //Constructor
  NODETYPE getData() const;             //Return data in the node
private:
  NODETYPE data;
  ListNode< NODETYPE > *nextPtr;        //Next node in the list
};

//Constructor
template< typename NODETYPE > ListNode< NODETYPE >::ListNode( const NODETYPE &info ) : data( info ), nextPtr( 0 )
{
  //Empty body
}

//Return a copy for data in the node
template< typename NODETYPE > NODETYPE ListNode< NODETYPE >::getData() const
{
  return data;
}





#endif //LISTNODE_H
