# Project 76: Sorted Array for Dictionary Lookup

## Overview
A dictionary application that stores words and their definitions in a **sorted array** for efficient lookup using **binary search**. This project demonstrates the benefits of maintaining sorted data for fast retrieval operations.

## Key Features

✅ **Store words and definitions** - Add word-definition pairs to the dictionary  
✅ **Binary search lookup** - Efficiently search for words in O(log n) time  
✅ **Display definitions** - View definitions of specific words  
✅ **Maintain sort order** - Automatically insert new words in alphabetical order  
✅ **Add new words** - Insert words while preserving the sorted property  
✅ **Remove words** - Delete words from the dictionary  
✅ **Display all entries** - View the complete dictionary contents  

## Data Structure

```
Sorted Array of Structures (Entry)
└── Entry {
    ├── std::string word
    └── std::string definition
}
```

The array is maintained in **alphabetical order** by word, enabling efficient binary search operations.

## Time Complexity Analysis

| Operation | Time Complexity | Notes |
|-----------|-----------------|-------|
| Search | O(log n) | Binary search in sorted array |
| Insert | O(n) | Requires shifting elements |
| Delete | O(n) | Requires shifting elements |
| Display All | O(n) | Iterate through all entries |

## Algorithm Details

### Binary Search for Lookup
Finds an exact match for a word:
```
- Compare middle element with target
- If match found → return index
- If middle < target → search right half
- If middle > target → search left half
- Continue until found or range is exhausted
```

### Binary Search for Insertion
Finds the correct position to insert a new word:
```
- Find the leftmost position where word should be inserted
- Uses binary search to locate this position in O(log n)
- Array insertion at found position (O(n) for shifting)
```

### Maintaining Sort Order
When adding a word:
1. Check if word already exists (using binary search)
2. Find correct insertion position (using binary search)
3. Insert at position while shifting elements
4. Array remains sorted alphabetically

## Files

| File | Purpose |
|------|---------|
| `dictionary.h` | Header file with Dictionary class declaration |
| `dictionary.cpp` | Implementation of Dictionary class methods |
| `main.cpp` | Interactive menu-driven interface and test program |
| `Makefile` | Build configuration |
| `README.md` | This file |

## Building the Project

### Using Makefile (Recommended)
```bash
# Build the project
make

# Run the program
make run

# Clean build artifacts
make clean

# Rebuild from scratch
make rebuild
```

### Manual Compilation
```bash
g++ -std=c++11 -Wall -Wextra -o dictionary main.cpp dictionary.cpp
./dictionary
```

## Usage

The program provides an interactive menu with the following options:

```
1. Add a word        - Add a new word with its definition
2. Search for word   - Search for a word (returns definition if found)
3. Display definition - Show the definition of a specific word
4. Display all words - Show all words and definitions in order
5. Remove a word     - Delete a word from the dictionary
6. Check size        - Display total number of entries
7. Run demo          - Load sample data for testing
8. Exit              - Quit the program
```

### Example Session

```
Enter your choice (1-8): 1

--- Add a New Word ---
Enter word: algorithm
Enter definition: A step-by-step procedure for solving a problem.
Word 'algorithm' added successfully!

Enter your choice (1-8): 2

--- Search for a Word ---
Enter word to search: algorithm
Word found!
Definition: A step-by-step procedure for solving a problem.

Enter your choice (1-8): 4

========== Dictionary Contents ==========
1. algorithm
   Definition: A step-by-step procedure for solving a problem.
=========================================
```

## Implementation Highlights

### Entry Structure
```cpp
struct Entry {
    std::string word;           // The word to lookup
    std::string definition;     // Definition of the word
};
```

### Dictionary Class
- **Private Members:**
  - `std::vector<Entry> entries` - Maintains sorted entries
  - `binarySearch()` - Find exact word match
  - `binarySearchForInsert()` - Find insertion position

- **Public Methods:**
  - `addWord()` - Add word maintaining sort order
  - `searchWord()` - Look up a word's definition
  - `displayDefinition()` - Show definition of a word
  - `displayAll()` - Print entire dictionary
  - `removeWord()` - Remove a word
  - `wordExists()` - Check word existence
  - `getSize()` - Get entry count

## Why Use Sorted Arrays with Binary Search?

### Advantages
✓ **Fast lookup** - O(log n) instead of O(n) for linear search  
✓ **Space efficient** - Only two fields per entry  
✓ **Simple implementation** - Straightforward binary search algorithm  
✓ **Cache friendly** - Contiguous array in memory  
✓ **Alphabetically ordered** - Natural display order  

### Trade-offs
✗ **Insertion cost** - O(n) due to array shifting  
✗ **Deletion cost** - O(n) due to array shifting  
✗ **Fixed ordering** - Cannot have custom sort orders  

### Best For
- **Frequent lookups, infrequent additions** - Ideal use case
- **Alphabetically sorted display** - Words naturally ordered
- **Small to medium sized data** - Array overhead minimal

## Alternative Data Structures

For comparison:
- **Hash Table** - O(1) average lookup, but no ordering
- **Binary Search Tree** - O(log n) lookup, O(log n) insert
- **Balanced BST** - Better insertion/deletion, more complex
- **Trie** - Fast prefix matching, more memory

## Compilation Notes

- Requires C++11 or later
- Uses standard library (vector, string)
- No external dependencies
- Tested with g++ compiler

## Potential Enhancements

1. **Case-insensitive search** - Already implemented in main
2. **Prefix search** - Find all words starting with prefix
3. **Fuzzy matching** - Handle typos and similar words
4. **Persistence** - Save/load dictionary from file
5. **Web interface** - HTTP API for remote access
6. **Performance metrics** - Time lookup operations
7. **Multiple definitions** - Support multiple meanings per word
8. **Word statistics** - Track usage frequency

## Learning Objectives

By studying this project, you'll learn:
- ✓ Sorted array implementation and maintenance
- ✓ Binary search algorithm and variations
- ✓ Time complexity analysis
- ✓ Trade-offs between different data structures
- ✓ C++ STL containers (vector, string)
- ✓ Object-oriented programming with classes
- ✓ Menu-driven application design

## Author Notes

This project demonstrates a fundamental principle in computer science: **appropriate data structure choice** leads to significant performance improvements. The sorted array paired with binary search provides a classic example of O(log n) performance for read-heavy workloads.
