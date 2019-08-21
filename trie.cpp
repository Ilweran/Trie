/*
 * trie.cpp
 *
 *  Created on: Aug 3, 2019
 *      Author: eugene
 */
#include <iostream>
#include "trie.h"
using namespace std;

// A Class representing a Trie node

// Iterative function to insert a key in the Trie
void TrieNode::insertString(std::string key)
{
	// start from root node
	TrieNode* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		// create a new node if path doesn't exist
		if (curr->symbol[key[i]] == nullptr)
			curr->symbol[key[i]] = new TrieNode();
		// go to next node
  	curr = curr->symbol[key[i]];
	}

	// mark current node as leaf
	curr->isLeaf = true;
}

// Iterative function to search a key in Trie. It returns true
// if the key is found in the Trie, else it returns false
bool TrieNode::searchString(std::string key)
{
	// return false if Trie is empty
	if (this == nullptr)
		return false;

	TrieNode* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		// go to next node
		curr = curr->symbol[key[i]];

		// if string is invalid (reached end of path in Trie)
		if (curr == nullptr)
			return false;
	}

	// if current node is a leaf and we have reached the
	// end of the string, return true
	return curr->isLeaf;
}

// returns true if given node has any children
bool TrieNode::haveChildren(TrieNode const* curr)
{
	for (int i = 0; i < CHAR_SIZE; i++)
		if (curr->symbol[i])
			return true;	// child found

	return false;
}

// Recursive function to delete a key in the Trie
bool TrieNode::deleteString(TrieNode*& curr, std::string key)
{
	// return if Trie is empty
	if (curr == nullptr)
		return false;

	// if we have not reached the end of the key
	if (key.length())
	{
		// recur for the node corresponding to next character in the key
		// and if it returns true, delete current node (if it is non-leaf)

		if (curr != nullptr &&
			curr->symbol[key[0]] != nullptr &&
			deleteString(curr->symbol[key[0]], key.substr(1)) &&
			curr->isLeaf == false)
		{
			if (!haveChildren(curr))
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
	if (key.length() == 0 && curr->isLeaf)
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
			curr->isLeaf = false;

			// don't delete its parent nodes
			return false;
		}
	}

	return false;
}
