#include "trie.h"

#include <iostream>
#include <cstring>


int main()
{
        TrieNode* head = new TrieNode();

        head->insertString("hello");
        std::cout << "\ninvoke searchString(\"hello\"): " << head->searchString("hello") << std::endl;              // print 1

        head->insertString("helloworld");
        std::cout << "invoke searchString(\"helloworld\"): " << head->searchString("helloworld") << std::endl; // print 1

        std::cout << "invoke searchString(\"helll\"): " << head->searchString("helll") << std::endl;              // print 0 (Not found)

        head->insertString("hell");
        std::cout << "invoke searchString(\"hell\"): " << head->searchString("hell") << std::endl;               // print 1

        head->insertString("h");
        std::cout << "invoke searchString(\"h\"): " << head->searchString("h");                                 // print 1

        std::cout << std::endl;

	std::cout << "invoke deleteString(head, \"hello\"): " << std::endl;
        head->deleteString(head, "hello");
        std::cout << "\ninvoke searchString(\"hello\"): " << head->searchString("hello") << std::endl;              // print 0 ("hello" deleted)
        std::cout << "\ninvoke searchString(\"helloworld\"): " << head->searchString("helloworld") << std::endl; // print 1
        std::cout << head->searchString("hell");                              // print 1

        std::cout << std::endl;

        head->deleteString(head, "h");
        std::cout << head->searchString("h") << " ";                  // print 0 ("h" deleted)
        std::cout << head->searchString("hell") << " ";               // print 1
        std::cout << head->searchString("helloworld");                 // print 1

        std::cout << std::endl;

        head->deleteString(head, "helloworld");
        std::cout << head->searchString("helloworld") << " "; // print 0 ("helloworld" deleted)
        std::cout << head->searchString("hell") << " ";               // print 1

        head->deleteString(head, "hell");
        std::cout << head->searchString("hell");                              // print 0

        std::cout << std::endl;

        if (head == nullptr)
                std::cout << "TrieNode empty!!\n";                          // TrieNode is empty now

        std::cout << head->searchString("hell");                              // print 0

        return 0;
}

