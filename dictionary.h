#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Entry {
    string word;
    string definition;
    
    Entry(const string& w = "", const string& d = "")
        : word(w), definition(d) {}
};

// Dictionary class using sorted array
class Dictionary {
private:
    vector<Entry> entries;
    
    int binarySearchForInsert(const string& word) const;
    int binarySearch(const string& word) const;

public:
    Dictionary();
    
    bool addWord(const string& word, const string& definition);
    bool searchWord(const string& word, string& definition) const;
    void displayDefinition(const string& word) const;
    void displayAll() const;
    int getSize() const;
    bool removeWord(const string& word);
    bool wordExists(const string& word) const;
};

#endif // DICTIONARY_H
