/*
 * trie.h
 *
 *  Created on: Aug 3, 2019
 *      Author: Ilweran
 */

#ifndef TRIE_H_
#define TRIE_H_

#include<iostream>
#include <string>
#include "trienode.h"
using namespace std;

class Trie
{
public:
  Trie()
  {
    root = new TrieNode();
    dummy = new TrieNode();
  }

  ~Trie()
  {
    
  }

private:
  TrieNode* root;
  TrieNode* dummy;
};


#endif /* TRIE_H_ */
