#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Structure to hold a word and its definition
struct Entry {
    string word;
    string definition;
    
    // Constructor
    Entry(const string& w = "", const string& d = "")
        : word(w), definition(d) {}
};

// Dictionary class using sorted array
class Dictionary {
private:
    vector<Entry> entries;
    
    // Helper function: Binary search to find insertion position
    int binarySearchForInsert(const string& word) const;
    
    // Helper function: Binary search to find a word
    int binarySearch(const string& word) const;

public:
    // Constructor
    Dictionary();
    
    // Add a new word with its definition (maintaining sort order)
    bool addWord(const string& word, const string& definition);
    
    // Search for a word and return its definition
    bool searchWord(const string& word, string& definition) const;
    
    // Display a specific definition
    void displayDefinition(const string& word) const;
    
    // Display all words and definitions
    void displayAll() const;
    
    // Get total number of entries
    int getSize() const;
    
    // Remove a word from the dictionary
    bool removeWord(const string& word);
    
    // Check if a word exists
    bool wordExists(const string& word) const;
};

#endif // DICTIONARY_H
