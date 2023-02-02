//  Created by Hannah Jeffi Leo Paul -Student No:2279688 [12/04/2022]
// Word Tree Implementation File - This file contains methods to add a word into the binary tree,
// count unique words of binary tree and print the words and occurances in alphabetical order
#include <iostream>
#include <string>
#include "WordTree.h"

using namespace std;

/// @brief Public method to add the word in the Tree if not present or increment its occurances
/// @param input The word to be added
/// @pre The root should be either null or has some value , input should be a single word.
/// @post If word already present increments or Adds a new WordNode to Tree
/// @function called : addToTree(WordNode *&node, string word)
void WordTree::add(string input)
{
  addToTree(root_, input);
}

/// @brief Recursive Helper method for the add() method.
///        Adds the word to tree or increment occurances if already present
/// @param node Current node for implementing recursion
/// @param word The word to be added.
void WordTree::addToTree(WordNode *&node, string word)
{
  if (node == nullptr)
  {
    node = new WordNode(word);
    return;
  }
  if (node->word_ == word)
  {
    node->occurances_++;
    return;
  }
  if (node->word_ > word)
  {
    addToTree(node->left_, word);
  }
  else
    addToTree(node->right_, word);
}

/// @brief Prints the WordTree with occurances in ascending order.
///        In-order Traversal is used
/// @param os The object of output stream
/// @param t  Object of the class
/// @return Object of the output stream
/// @function called : printTree(ostream &os, const WordNode *node)
ostream &operator<<(ostream &os, const WordTree &t)
{
  t.printTree(os, t.root_);
  return os;
}

/// @brief Recursively clears the tree by de allocating the dynamically allocated memory
/// @param node The current node in tree
ostream &WordTree::printTree(ostream &os, const WordNode *node) const
{
  if (node == nullptr)
  {
    return os;
  }
  // In-order Traversal
  printTree(os, node->left_);
  os << node->word_ << " : " << node->occurances_ << endl;
  printTree(os, node->right_);
  return os;
}

/// @brief Returns the number of (unique) words currently stored in the tree.
///        Post-order traversal is used
/// @return The count of unique words in Tree
/// @pre A WordTree initialised
/// @post WordTree unchanged and the count of unique words
/// @function called : numWordsHelper(WordNode *node)
int WordTree::numWords() const
{
  return numWordsHelper(root_);
}

/// @brief Recursive Helper method for numWords() to find the unique words using pre order Traversal
/// @param node The current node for implementiing recursion
/// @return The count of unique words
int WordTree::numWordsHelper(const WordNode *node) const
{
  if (node == nullptr)
  {
    return 0;
  }
  return 1 + numWordsHelper(node->left_) + numWordsHelper(node->right_);
}

///  @brief Destructor of the class which clears the dynamically allocated memory
///  @method called : clear();
WordTree::~WordTree()
{
  clear(root_);
  root_ = nullptr;
}

/// @brief Recursively clears the tree by de allocating the dynamically allocated memory using post order traversal
/// @param node The current node in tree
void WordTree::clear(WordNode *node)
{
  if (node == nullptr)
  {
    return;
  }
  clear(node->left_);
  clear(node->right_);
  delete node;
}