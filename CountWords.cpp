//  Created by Hannah Jeffi Leo Paul -Student No:2279688 [12/04/2022]
// CountWords Driver File - This file is the main driver class for CountWords, It adds the words to the binary tree , count the unique words and print the binary tree
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include "WordTree.h"

using namespace std;

/// @brief The method is used to form a word using valid characters and add the word to tree if any invalid char has occurred
/// @param t Object of the WordTree
/// @param input char read from cin
/// @param word The word to be added to the tree
void seperateInput(WordTree &t, char input, string &word)
{
   // Ignoring input other than alphabet and apostrophe
   if (isalpha(input) || input == 39)
   {
      // Forming a word if char is valid
      word.push_back(tolower(input));
   }
   else
   {
      // If char is invalid passing the word formed to add() method to add it in the tree
      if (word != "")
      {
         t.add(word);
         // Reseting the word
         word = "";
      }
   }
}

/// @brief The method is used to get char by char input from user and send it to seperate input to split words.
/// @param t The object of the tree
void getinput(WordTree &t)
{
   string word = "";
   char input;
   // Looping untill an EOF is reached CTR+D is hit
   while (cin.peek() != EOF)
   {
      // passing the char to the method seperateinput() in order to ignore char other than alphabet abd apostrophe
      seperateInput(t, cin.get(), word);
   }
   // Adding if any remaining word is present
   if (word != "")
   {
      t.add(word);
   }
}

int main()
{
   WordTree t;
   cout << "Please enter the words to be added" << endl;
   getinput(t);
   cout << "The words are" << endl;
   cout << t << endl;
   cout << "The number of unique words in the tree are  " << t.numWords() << endl;
   return 0;
}
