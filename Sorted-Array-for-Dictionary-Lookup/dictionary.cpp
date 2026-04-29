#include "dictionary.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
Dictionary::Dictionary() {
    // Initialize empty vector
}

// Helper function: Binary search to find a word (exact match)
// Returns index if found, -1 otherwise
int Dictionary::binarySearch(const string& word) const {
    int left = 0;
    int right = entries.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (entries[mid].word == word) {
            return mid;  // Found
        } else if (entries[mid].word < word) {
            left = mid + 1;  // Search right
        } else {
            right = mid - 1;  // Search left
        }
    }
    
    return -1;  // Not found
}

// Helper function: Binary search to find insertion position
// Returns the index where the word should be inserted to maintain sort order
int Dictionary::binarySearchForInsert(const string& word) const {
    int left = 0;
    int right = entries.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (entries[mid].word < word) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

// Add a new word with its definition (maintaining sort order)
bool Dictionary::addWord(const string& word, const string& definition) {
    // Check if word already exists
    if (wordExists(word)) {
        cout << "Error: Word '" << word << "' already exists in dictionary.\n";
        return false;
    }
    
    // Find insertion position
    int insertPos = binarySearchForInsert(word);
    
    // Insert at the correct position
    entries.insert(entries.begin() + insertPos, Entry(word, definition));
    
    return true;
}

// Search for a word and return its definition
bool Dictionary::searchWord(const string& word, string& definition) const {
    int index = binarySearch(word);
    
    if (index != -1) {
        definition = entries[index].definition;
        return true;
    }
    
    return false;
}

// Display a specific definition
void Dictionary::displayDefinition(const string& word) const {
    string definition;
    
    if (searchWord(word, definition)) {
        cout << "\nWord: " << word << endl;
        cout << "Definition: " << definition << endl;
    } else {
        cout << "\nWord '" << word << "' not found in dictionary.\n";
    }
}

// Display all words and definitions
void Dictionary::displayAll() const {
    if (entries.empty()) {
        cout << "\nDictionary is empty.\n";
        return;
    }
    
    cout << "\n========== Dictionary Contents ==========\n";
    for (size_t i = 0; i < entries.size(); ++i) {
        cout << (i + 1) << ". " << entries[i].word << "\n";
        cout << "   Definition: " << entries[i].definition << "\n";
    }
    cout << "=========================================\n";
}

// Get total number of entries
int Dictionary::getSize() const {
    return entries.size();
}

// Remove a word from the dictionary
bool Dictionary::removeWord(const string& word) {
    int index = binarySearch(word);
    
    if (index != -1) {
        entries.erase(entries.begin() + index);
        cout << "Word '" << word << "' removed successfully.\n";
        return true;
    }
    
    cout << "Word '" << word << "' not found in dictionary.\n";
    return false;
}

// Check if a word exists
bool Dictionary::wordExists(const std::string& word) const {
    return binarySearch(word) != -1;
}
