#include "dictionary.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Function to display menu
void displayMenu() {
    cout << "\n========== Dictionary Menu ==========\n";
    cout << "1. Add a word\n";
    cout << "2. Search for a word\n";
    cout << "3. Display a definition\n";
    cout << "4. Display all words\n";
    cout << "5. Remove a word\n";
    cout << "6. Check dictionary size\n";
    cout << "7. Run demo with sample data\n";
    cout << "8. Exit\n";
    cout << "====================================\n";
}

// Convert string to lowercase for case-insensitive operations
string toLower(const string& str) {
    string result = str;
    for (char& c : result) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return result;
}

// Main program
int main() {
    Dictionary dict;
    int choice;
    string word, definition;
    
    cout << "====== Sorted Array Dictionary ======\n";
    cout << "Using Binary Search for Lookup\n";
    cout << "=====================================\n";
    
    while (true) {
        displayMenu();
        cout << "Enter your choice (1-8): ";
        cin >> choice;
        cin.ignore();  // Clear the newline from input buffer
        
        switch (choice) {
            case 1: {
                // Add a word
                cout << "\n--- Add a New Word ---\n";
                cout << "Enter word: ";
                getline(cin, word);
                word = toLower(word);
                
                cout << "Enter definition: ";
                getline(cin, definition);
                
                if (dict.addWord(word, definition)) {
                    cout << "Word '" << word << "' added successfully!\n";
                }
                break;
            }
            
            case 2: {
                // Search for a word
                cout << "\n--- Search for a Word ---\n";
                cout << "Enter word to search: ";
                getline(cin, word);
                word = toLower(word);
                
                if (dict.searchWord(word, definition)) {
                    cout << "Word found!\n";
                    cout << "Definition: " << definition << "\n";
                } else {
                    cout << "Word '" << word << "' not found in dictionary.\n";
                }
                break;
            }
            
            case 3: {
                // Display definition
                cout << "\n--- Display Definition ---\n";
                cout << "Enter word: ";
                getline(cin, word);
                word = toLower(word);
                dict.displayDefinition(word);
                break;
            }
            
            case 4: {
                // Display all words
                dict.displayAll();
                break;
            }
            
            case 5: {
                // Remove a word
                cout << "\n--- Remove a Word ---\n";
                cout << "Enter word to remove: ";
                getline(cin, word);
                word = toLower(word);
                dict.removeWord(word);
                break;
            }
            
            case 6: {
                // Check dictionary size
                cout << "\nDictionary currently has " << dict.getSize() 
                          << " word(s).\n";
                break;
            }
            
            case 7: {
                // Run demo with sample data
                cout << "\n--- Loading Sample Data ---\n";
                
                dict.addWord("algorithm", "A step-by-step procedure for solving a problem.");
                dict.addWord("binary", "Relating to, composed of, or involving two things.");
                dict.addWord("compile", "To convert source code into executable code.");
                dict.addWord("data", "Facts and statistics collected together for analysis.");
                dict.addWord("efficient", "Achieving maximum productivity with minimum effort.");
                dict.addWord("function", "A reusable block of code that performs a specific task.");
                dict.addWord("hash", "A function that maps data to a fixed size value.");
                dict.addWord("iteration", "The repetition of a process or action.");
                dict.addWord("logic", "A system of reasoning or principles.");
                dict.addWord("memory", "Storage space for data in a computer.");
                
                cout << "Sample data loaded! Dictionary now has " << dict.getSize() 
                          << " words.\n";
                dict.displayAll();
                break;
            }
            
            case 8: {
                // Exit
                cout << "\nThank you for using the Dictionary!\n";
                cout << "Goodbye!\n";
                return 0;
            }
            
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 8.\n";
            }
        }
    }
    
    return 0;
}
