#ifndef TRIENODE_H
#define TRIENODE_H

const unsigned int ALPHABET_SIZE = 128;

//Leading declaration of class Trie
class Trie;

//Definition of TrieNode template
class TrieNode
{
  friend class Trie;
public:
  //Constructor
  TrieNode()
  {
    for ( int i = 0; i < ALPHABET_SIZE; i++)
      symbol[i] = nullptr;
    isLeaf = false;
    isWord = false;
  }
  ~TrieNode();    //To be defined later

private:
  TrieNode * symbol[ALPHABET_SIZE];
  bool isWord;
  bool isLeaf;
};

#endif //TRIENODE_H
