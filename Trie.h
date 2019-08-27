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
  int searchLongestWord() const;
  bool haveChildren(TrieNode * curr) const;
  bool deleteNode(string str);
  bool deleteString(TrieNode * curr, string str);
  void dfs() const;
private:
  TrieNode *rootPtr;  // Points to the top TrieNode
  TrieNode *lastPtr;  //Points to the last TrieNode being pointed to by all leaf TrieNodes
  TrieNode *markPtr;  //A marker that is used to point to found TrieNode
                      //which is set to nullptr otherwise
  unsigned short int longestWord; //:
  /*This is tracked by the Trie during inserting each new word into itself
  so that later when preparing to print words from itself it could allocate enough array
  indices to address all required characters of a word including the longest one that it contains*/
  string word;  //:
  /*This variable is used in depth first search Trie traversal algorithm to store detected string sequences
  of key elements present in the Trie
  */
};

#endif /* TRIE_H_ */
