
# Word Counting using a Binary Search Tree

This is a C++ program that counts the occurrences of words in a text document using a binary search tree (BST). It provides a simple yet effective way to analyze and count words in a given text, ignoring case sensitivity and handling various word formats, such as contractions and hyphenated words.

## Table of Contents

- [Overview](#overview)
- [Learning Goals](#learning-goals)
- [Implementation Details](#implementation-details)
- [Usage](#usage)


## Overview

The program reads text input character by character, separates valid words, and adds them to the binary search tree. It ensures that the word counts are case-insensitive, meaning that "the," "The," "THE," and "tHe" are all considered the same word. The program handles words in various formats, such as contractions (e.g., "don't") and hyphenated words (e.g., "best-selling").

## Learning Goals

- Gain experience with dynamically allocated Abstract Data Types (ADTs).
- Practice using pointers in C++.
- Implement a binary search tree with different tree traversals (preorder, inorder, and postorder).
- Use nested classes within C++.
- Gain proficiency in recursion.
- Manipulate text in C++.

## Implementation Details

### WordTree Class

The core class for this program is `WordTree`, which contains the following public functions:

1. **add(string input)**: Adds a word to the binary tree if it is not already present or increments its occurrences if it already exists.

2. **numWords()**: Returns the number of unique words stored in the tree.

3. **Stream Output Operator `<<`**: Prints the words of the tree in alphabetical order, along with the number of times each word occurs in the text.

### WordNode

The `WordNode` structure is defined as nested within the `WordTree` class, allowing for the organization of words and their counts. It has a constructor to initialize words and occurrences.

## Usage

1. Clone this repository to your local machine.

2. Compile the program. For example, using g++, you can run:

   ```bash
   g++ -o CountWords CountWords.cpp WordTree.cpp
   ```

3. Run the program by providing text input. For example:

   ```bash
   ./CountWords < input.txt
   ```

   Replace `input.txt` with your text file.

4. The program will output the sorted word count along with the number of unique words.

