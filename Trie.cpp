/*
 * trie.cpp
 *
 *  Created on: Aug 3, 2019
 *      Author: eugene
 */
#include <iostream>
#include "Trie.h"
using namespace std;


Trie::Trie()
{
  rootPtr = nullptr;  //Trie is empty at the beginning
  lastPtr = nullptr; //:
  /*Pointer to the dummy TrieNode which serves as the last object
  which is being pointed at by all leaf TrieNodes. A Trie must create it
   */
  markPtr = nullptr;
  longestWord = 0; //No words, no knowledge
}

// Iterative function to insert a key in the Trie
void Trie::insertString(string str)
{
  //Check if Trie is empty and create the top TrieNode if it is
  if ( rootPtr == nullptr )
    rootPtr = new TrieNode;

	// Now when Trie is not empty let's start inserting a string from root node
	TrieNode* curr = rootPtr;
	for (unsigned short int i = 0; i < str.length(); i++)
	{
		// create a new node if path doesn't exist
		if (curr->TrieNode::letter[str[i]] == nullptr)
			curr->TrieNode::letter[str[i]] = new TrieNode();
		// go to next node
  	curr = curr->TrieNode::letter[str[i]];
	}
	// mark current node as leaf
	curr->TrieNode::setIsLeaf();
  if ( longestWord < str.size() )
    longestWord = str.size();
}

// Iterative function to search a key in Trie. It returns true
// if the key is found in the Trie, otherwise returns false
bool Trie::searchString(string str)
{
	// return false if Trie is empty
	if (rootPtr == nullptr)
		return false;

	TrieNode* curr = rootPtr;
	for (unsigned short int i = 0; i < str.length(); i++)
	{
		// go to next node
		curr = curr->TrieNode::letter[str[i]];

		// if string is invalid (reached end of path in Trie)
		if (curr == nullptr)
			return false;
	}
	// if current node is a leaf then we have reached the
	// end of the string, set markPtr, check and set longestWord and return true
	if ( curr->TrieNode::getIsLeaf() )
	{
	  markPtr = curr;
	  if ( longestWord < str.size() )
	    longestWord = str.size();
	}
	return true;
}

// Returns true if given node has any children
bool Trie::haveChildren(TrieNode * curr) const
{
	for (unsigned short int i = 0; i < ALPHABET_SIZE; i++)
		if (curr->getNextNode(i) != nullptr)
			return true;	// A child found :)
	return false;     //Childless :(
}

bool Trie::deleteNode(string prefix)
{
  if ( rootPtr == nullptr )
    return false;
  if (Trie::searchString(prefix))
  {
    delete markPtr;
    markPtr = nullptr;
  }
  if ( longestWord == prefix.size() ) //If we are deleting a node for the longest word in the Trie
    longestWord--;                    //Adjust longestWord
  return true;
}

// Recursive function to delete a key in the Trie
bool Trie::deleteString(TrieNode * curr, string str)
{
	// return if Trie is empty
	if (rootPtr == nullptr)
		return false;
	curr = rootPtr;
	// While we have not reached the end of the key
	if (str.length())
	{
		// Recur for the node corresponding to next character in the key
		// and if it returns true, delete current node (if it is non-leaf)
		if (curr != nullptr &&
			curr->TrieNode::getNextNode(str[0]) != nullptr &&
			deleteString(curr->getNextNode(str[0]), str.substr(1)) &&
			curr->TrieNode::getIsLeaf() == false)
		{
			if (!Trie::haveChildren(curr))
			{
				delete curr;
				curr = nullptr;
				return true;
			}
			else {
				return false;
			}
		}
	}
	// if we have reached the end of the key
	if (str.length() == 0 && curr->getIsLeaf())
	{
		// if current node is a leaf node and don't have any children
		if (!haveChildren(curr))
		{
			// delete current node
			delete curr;
			curr = nullptr;

			// delete non-leaf parent nodes
			return true;
		}
		// if current node is a leaf node and have children
		else
		{
			// mark current node as non-leaf node (DON'T DELETE IT)
			curr->setIsLeaf(false);
			// don't delete its parent nodes
			return false;
		}
	}

	return false;
}

void Trie::dfs() const
{
  if (rootPtr == nullptr)
    return;
  for(unsigned short int i = 0; i < ALPHABET_SIZE; i++)
  {
    if ( TrieNode::letter[i] != nullptr )
      word += (char)i;
  }
}

int Trie::searchLongestWord() const
{
  //dfs() comes here
  return longestWord;
}
