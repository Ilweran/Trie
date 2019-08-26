/*
 * trie.h
 *
 *  Created on: Aug 3, 2019
 *      Author: Ilweran
 */

#ifndef TRIE_H_
#define TRIE_H_

#include "TrieNode.h"
#include <iostream>
#include <cstring>
using namespace std;

class Trie
{
public:
  Trie();
  ~Trie();
  void insertString(string str);
  bool searchString(string str);
  bool haveChildren(TrieNode * curr);
  bool deleteNode(string str);
  bool deleteString(TrieNode * curr, string str);
  void dfs() const;
private:
  TrieNode *rootPtr;  // Points to the top TrieNode
  TrieNode *lastPtr;  //Points to the last TrieNode being pointed to by all leaf TrieNodes
  TrieNode *markPtr;  //A marker that is used to point to found TrieNode
                      //which is set to nullptr otherwise
  unsigned int longestWord; //:
  /*This is tracked by the Trie during inserting each new word into itself
  so that later when preparing to print words from itself it could allocate enough array
  indices to address all required characters of a word including the longest one that it contains*/
};

#endif /* TRIE_H_ */
