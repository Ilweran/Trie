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
#define CHAR_SIZE 128


class Trie
{
public:
	bool isLeaf;
	Trie* character[CHAR_SIZE];

	// Constructor
	Trie()
	{
		this->isLeaf = false;

		for (int i = 0; i < CHAR_SIZE; i++)
			this->character[i] = nullptr;
	}

	void insertString(std::string);
//	bool inputCommand(std::string);
	bool deleteString(Trie*&, std::string);
	bool searchString(std::string);
	bool haveChildren(Trie const*);
};

#endif /* TRIE_H_ */
