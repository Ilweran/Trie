#ifndef TRIENODE_H
#define TRIENODE_H

const unsigned int ALPHABET_SIZE = 26; //Lowercase English letters

//Forward declaration of class Trie
class Trie;

//Definition of TrieNode template
class TrieNode
{
  friend class Trie;
public:
  //Constructor
  TrieNode()
  {
    for (unsigned short int i = 0; i < ALPHABET_SIZE; i++)
      letter[i] = nullptr;
    isLeaf = false;
    isWord = false;
  }

  /*There is no destructor inside TrieNode definition
  since a TrieNode can't know how to delete itself properly,
  only the structure that holds the node can see what
  has to be done to delete current node and not loose
  pointers to other possible descendants of it*/

  void setIsLeaf()
  {
    isLeaf = true;
  }
  void unsetIsLeaf()
  {
    isLeaf = false;
  }
  void setIsWord()
  {
    isWord = true;
  }
  bool getIsLeaf()
  {
    return isLeaf;
  }
  void setIsLeaf(bool b)
  {
    isLeaf = b;
  }
  TrieNode* getNextNode(unsigned short int index)
  {
    return letter[index];
  }
private:
  TrieNode * letter[ALPHABET_SIZE];
  bool isWord;
  bool isLeaf;
};

#endif //TRIENODE_H
