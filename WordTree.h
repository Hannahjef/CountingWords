//  Created by Hannah Jeffi Leo Paul -Student No:2279688 [12/04/2022]
// Word Tree Header File - This file contains the WordNode class nested inside WordTree class along with their variables and methods.
#include <iostream>
#include <string>
using namespace std;

class WordTree
{
private:
   struct WordNode
   {
      string word_;
      int occurances_;
      WordNode *left_;
      WordNode *right_;

   public:
      /// @brief Constructor for WordNode uses initialization list.
      /// @param word The word that has to be added to the node
      WordNode(string word) : word_{word}, occurances_{1}, left_{nullptr}, right_{nullptr} {};
   };
   WordNode *root_;

public:
   /// @brief  Constructor of WordTree:initializes the root to nullptr
   WordTree() : root_{nullptr} {};

   ///  @brief Destructor of the class which clears the dynamically allocated memory
   ///  @method called : clear();
   ~WordTree();

   /// @brief Public method to add the word in the Tree if not present or increment its occurances
   /// @param input The word to be added
   /// @pre The root should be either null or has some value
   /// @post If word already present increments or Adds a new WordNode to Tree
   /// @function called : addToTree(WordNode *&node, string word)
   void add(string input);

   /// @brief Returns the number of (unique) words currently stored in the tree.
   ///        Post-order traversal is used
   /// @return The count of unique words in Tree
   /// @pre A WordTree initialised
   /// @post WordTree unchanged and the count of unique words
   /// @function called : numWordsHelper(WordNode *node)
   int numWords() const;

   /// @brief Prints the WordTree with occurances in ascending order.
   ///        In-order Traversal is used
   /// @param os The object of output stream
   /// @param t  Object of the class
   /// @return Object of the output stream
   /// @function called : printTree(ostream &os, const WordNode *node)
   friend ostream &operator<<(ostream &os, const WordTree &t);

private:
   /// @brief Recursive Helper method for the add() method.
   ///        Adds the word to tree or increment occurances if already present
   /// @param node Current node for implementing recursion
   /// @param word The word to be added.
   void addToTree(WordNode *&node, string word);

   /// @brief Recursive Helper method for numWords() to find the unique words
   /// @param node The current node for implementiing recursion
   /// @return The count of unique words
   int numWordsHelper(WordNode const *node) const;

   /// @brief Recursive helper method to print the tree with occurances in ascending order
   /// @param os Object of the output stream
   /// @param node The current node in the tree
   /// @return Returns the object of the output stream
   ostream &printTree(ostream &os, const WordNode *node) const;

   /// @brief Recursively clears the tree by de allocating the dynamically allocated memory
   /// @param node The current node in tree
   void clear(WordNode *node);
};
