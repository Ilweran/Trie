/*
 * trie.h
 *
 *  Created on: Aug 3, 2019
 *      Author: Ilweran
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
  void dfs() const;
private:
  TrieNode *rootPtr;
  TrieNode *leafPtr;
  unsigned int longestWord;
};

#endif /* TRIE_H_ */
