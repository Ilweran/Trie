/*
 * trie.h
 *
 *  Created on: Aug 3, 2019
 *      Author: eugene
 */

#ifndef TRIE_H_
#define TRIE_H_

#include"TrieNode.h"

template< typename NODETYPE > class Trie
{
public:
  Trie();
  void insertNode( const NODETYPE & );
  void preOrderTraversal() const;
private:
  TrieNode< NODETYPE > *rootPtr;
  void insertNodeHelper( TrieNode< NODETYPE >**, const NODETYPE & );
  void preOrderHelper( TrieNode< NODETYPE> * ) const;
};

#endif /* TRIE_H_ */
