#include <iostream>
#define ALPHABET_SIZE 26 //English ABC
using namespace std;

class TrieNode
{
public:
  TrieNode()  
  {
    if(initArray())
      flags = 0;
    else
      cout << "Couldn't create object of class TrieNode (low on memory?)" << endl;
  }

  bool initArray()
  {
    symbolArray = new (nothrow) TrieNode* [ALPHABET_SIZE];    

    if (symbolArray != nullptr)  // If array was successfully created 
    {
      for (int i=0; i<ALPHABET_SIZE; i++)
        symbolArray[i] = NULL;
      return true;
    }
    else
      return false;
  }

  ~TrieNode()
  {
    delete[] symbolArray;
  }

private:
  TrieNode* symbolArray[ALPHABET_SIZE];
  unsigned short flags;
};


class TrieNode
{
public:
        virtual ~TrieNode();
        bool GetIsLeaf() {return isLeaf;}
        void insertString(std::string);
//      bool inputCommand(std::string);
        bool deleteString(TrieNode*&, std::string);
        bool searchString(std::string);
        bool haveChildren(TrieNode const*);
};

