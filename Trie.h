/*
 * trie.h
 *
 *  Created on: Aug 3, 2019
 *      Author: eugene
 */

#ifndef TRIE_H_
#define TRIE_H_

#include"TrieNode.h"

class Trie
{
public:
  Trie();
  ~Trie();
  void insertNode( const TrieNode & );
  void preOrderTraversal() const;
private:
  TrieNode *rootPtr;
  TrieNode *leafPtr;
  void insertNodeHelper( TrieNode**, const TrieNode & );
  void preOrderHelper( TrieNode * ) const;
};

#endif /* TRIE_H_ */
