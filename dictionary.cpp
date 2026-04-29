#include "dictionary.h"
#include <iostream>
#include <algorithm>

using namespace std;

Dictionary::Dictionary() {}

int Dictionary::binarySearch(const string& word) const {
    int left = 0;
    int right = entries.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (entries[mid].word == word) {
            return mid;
        } else if (entries[mid].word < word) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

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

bool Dictionary::addWord(const string& word, const string& definition) {
    if (wordExists(word)) {
        cout << "Error: Word '" << word << "' already exists in dictionary.\n";
        return false;
    }
    
    int insertPos = binarySearchForInsert(word);
    entries.insert(entries.begin() + insertPos, Entry(word, definition));
    
    return true;
}

bool Dictionary::searchWord(const string& word, string& definition) const {
    int index = binarySearch(word);
    
    if (index != -1) {
        definition = entries[index].definition;
        return true;
    }
    
    return false;
}

void Dictionary::displayDefinition(const string& word) const {
    string definition;
    
    if (searchWord(word, definition)) {
        cout << "\nWord: " << word << endl;
        cout << "Definition: " << definition << endl;
    } else {
        cout << "\nWord '" << word << "' not found in dictionary.\n";
    }
}

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

int Dictionary::getSize() const {
    return entries.size();
}

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

bool Dictionary::wordExists(const std::string& word) const {
    return binarySearch(word) != -1;
}
