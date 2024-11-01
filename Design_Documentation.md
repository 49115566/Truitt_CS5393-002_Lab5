# Design Documentation for Lab 5

## Overview
This document provides a detailed design overview of the Trie-based dictionary implementation in `LAB_5-1.CPP`. The program reads words from a dataset file and performs various operations such as insertion, search, and retrieval of words based on specific criteria.

## Components

### TrieNode Class
- **Purpose**: Represents a single node in the Trie.
- **Attributes**:
    - `children`: An unordered map that stores child nodes.
    - `isEndOfWord`: A boolean flag indicating if the node represents the end of a word.
- **Constructor**: Initializes `isEndOfWord` to `false`.

### Trie Class
- **Purpose**: Manages the Trie data structure and provides methods for various operations.
- **Attributes**:
    - `root`: A pointer to the root node of the Trie.
- **Methods**:
    - `insert(const std::string& word)`: Inserts a word into the Trie.
    - `search(const std::string& word)`: Searches for a word in the Trie.
    - `startsWith(const std::string& prefix)`: Checks if any word in the Trie starts with the given prefix.
    - `findWordsWithPrefix(const std::string& prefix)`: Finds all words in the Trie that start with the given prefix.
    - `findShortWords()`: Finds all words in the Trie with a length of 2 or less.
    - `findHyphenatedWords()`: Finds all words in the Trie that contain a hyphen.
    - `findWordsWithNumbers()`: Finds all words in the Trie that contain numbers.
    - `findMixedCaseWords()`: Finds all words in the Trie that contain uppercase letters.
    - `findSpecialCaseWords()`: Finds specific special case words in the Trie.

### Main Function
- **Purpose**: Entry point of the program.
- **Operations**:
    - Reads words from `Lab5_dictionary-dataset.txt` and inserts them into the Trie.
    - Searches for specific words.
    - Finds words with given prefixes.
    - Retrieves short words, hyphenated words, words with numbers, mixed case words, and special case words.
    - Handles exceptions and memory management.

## Dataset
The dataset file `Lab5_dictionary-dataset.txt` contains various categories of words:
- Common English Prefixes
- Technical Terms
- Regular Words
- Short Words
- Compound Words
- Similar Words
- Special Cases
- Words with Numbers
- Case Variations
- Edge Cases

## Usage
1. **Insert Words**: Words from the dataset are inserted into the Trie.
2. **Search Words**: Specific words are searched in the Trie.
3. **Find Words with Prefix**: Words starting with given prefixes are retrieved.
4. **Retrieve Special Categories**: Short words, hyphenated words, words with numbers, mixed case words, and special case words are retrieved.

## Conclusion
This design document outlines the structure and functionality of the Trie-based dictionary implementation. The program efficiently handles various word operations using the Trie data structure, making it suitable for dictionary-related tasks.
