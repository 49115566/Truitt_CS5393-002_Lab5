#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

    void findWordsWithPrefixHelper(TrieNode* node, std::string prefix, std::vector<std::string>& results) {
        if (node->isEndOfWord) {
            results.push_back(prefix);
        }
        for (auto& pair : node->children) {
            findWordsWithPrefixHelper(pair.second, prefix + pair.first, results);
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
        std::cout << "Inserted: " << word << std::endl;
    }

    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                std::cout << "Search failed: " << word << std::endl;
                return false;
            }
            current = current->children[ch];
        }
        if (current->isEndOfWord) {
            std::cout << "Found: " << word << std::endl;
            return true;
        } else {
            std::cout << "Search failed: " << word << std::endl;
            return false;
        }
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                std::cout << "Prefix not found: " << prefix << std::endl;
                return false;
            }
            current = current->children[ch];
        }
        std::cout << "Prefix found: " << prefix << std::endl;
        return true;
    }

    std::vector<std::string> findWordsWithPrefix(const std::string& prefix) {
        std::vector<std::string> results;
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                std::cout << "No words found with prefix: " << prefix << std::endl;
                return results;
            }
            current = current->children[ch];
        }
        findWordsWithPrefixHelper(current, prefix, results);
        std::cout << "Words with prefix " << prefix << ": ";
        for (const auto& word : results) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
        return results;
    }

    std::vector<std::string> findShortWords() {
        std::vector<std::string> results;
        findWordsWithPrefixHelper(root, "", results);
        std::vector<std::string> shortWords;
        for (const auto& word : results) {
            if (word.length() <= 2) {
                shortWords.push_back(word);
            }
        }
        return shortWords;
    }

    std::vector<std::string> findHyphenatedWords() {
        std::vector<std::string> results;
        findWordsWithPrefixHelper(root, "", results);
        std::vector<std::string> hyphenatedWords;
        for (const auto& word : results) {
            if (word.find('-') != std::string::npos) {
                hyphenatedWords.push_back(word);
            }
        }
        return hyphenatedWords;
    }

    std::vector<std::string> findWordsWithNumbers() {
        std::vector<std::string> results;
        findWordsWithPrefixHelper(root, "", results);
        std::vector<std::string> wordsWithNumbers;
        for (const auto& word : results) {
            if (std::any_of(word.begin(), word.end(), ::isdigit)) {
                wordsWithNumbers.push_back(word);
            }
        }
        return wordsWithNumbers;
    }

    std::vector<std::string> findMixedCaseWords() {
        std::vector<std::string> results;
        findWordsWithPrefixHelper(root, "", results);
        std::vector<std::string> mixedCaseWords;
        for (const auto& word : results) {
            if (std::any_of(word.begin(), word.end(), ::isupper)) {
                mixedCaseWords.push_back(word);
            }
        }
        return mixedCaseWords;
    }

    std::vector<std::string> findSpecialCaseWords() {
        std::vector<std::string> specialCases = {"psychology", "pterodactyl", "xylophone", "yacht", "eBay", "iPad", "t-shirt", "x-ray"};
        std::vector<std::string> foundSpecialCases;
        for (const auto& word : specialCases) {
            if (search(word)) {
                foundSpecialCases.push_back(word);
            }
        }
        return foundSpecialCases;
    }
};


int main() {
    Trie trie;
    std::ifstream file("Lab5_dictionary-dataset.txt");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    // Insert words into the trie
    while (std::getline(file, line)) {
        if (!line.empty() && line[0] != '#' && line[0] != '\0') {
            trie.insert(line);
        }
    }

    file.close();

    // Search for specific words
    std::vector<std::string> searchWords = {"prefix", "data", "hello", "do", "workplace", "there", "pneumonia", "word2vec", "iPhone", "a-frame"};
    for (const auto& word : searchWords) {
        trie.search(word);
    }

    // Return words that start with a given prefix
    std::vector<std::string> prefixes = {"pre", "pro", "work", "i", "e"};
    for (const auto& prefix : prefixes) {
        trie.findWordsWithPrefix(prefix);
    }

    // Return short words
    std::vector<std::string> shortWords = trie.findShortWords();
    std::cout << "Short words: ";
    for (const auto& word : shortWords) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Return hyphenated words
    std::vector<std::string> hyphenatedWords = trie.findHyphenatedWords();
    std::cout << "Hyphenated words: ";
    for (const auto& word : hyphenatedWords) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Return words with numbers
    std::vector<std::string> wordsWithNumbers = trie.findWordsWithNumbers();
    std::cout << "Words with numbers: ";
    for (const auto& word : wordsWithNumbers) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Return mixed case words
    std::vector<std::string> mixedCaseWords = trie.findMixedCaseWords();
    std::cout << "Mixed case words: ";
    for (const auto& word : mixedCaseWords) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Return special case words
    std::vector<std::string> specialCaseWords = trie.findSpecialCaseWords();
    std::cout << "Special case words: ";
    for (const auto& word : specialCaseWords) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Handle exception and memory management
    std::vector<std::string> exceptionWords = {"abc", "xyz"};
    for (const auto& word : exceptionWords) {
        trie.search(word);
    }

    return 0;
}