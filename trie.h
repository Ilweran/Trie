/*
 * trie.h
 *
 *  Created on: Aug 3, 2019
 *      Author: eugene
 */

#ifndef TRIE_H_
#define TRIE_H_

#include<iostream>
#include <cstring>
#define CHAR_SIZE 128 //ASCII table


class TrieNode
{
public:
	TrieNode* symbol[CHAR_SIZE];

	// Constructor
	TrieNode()
	{
		this->isLeaf = false;

		for (int i = 0; i < CHAR_SIZE; i++)
			this->symbol[i] = nullptr;
	}
	virtual ~TrieNode();
	bool GetIsLeaf() {return isLeaf;}
	void insertString(std::string);
//	bool inputCommand(std::string);
	bool deleteString(TrieNode*&, std::string);
	bool searchString(std::string);
	bool haveChildren(TrieNode const*);
private:
	bool isLeaf;
};

#endif /* TRIE_H_ */
