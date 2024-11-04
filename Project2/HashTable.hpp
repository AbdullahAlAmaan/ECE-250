#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "FileBlock.hpp"

class HashTable {
private:
    FileBlock** table; // For separate chaining, each entry points to a FileBlock linked list
    unsigned int size; // Size of the hash table
    bool useOpenAddressing; // Flag to determine if open addressing is used

    int primaryHash(unsigned int key) const; // Primary hash function
    int secondaryHash(unsigned int key) const; // Secondary hash function

public:
    HashTable(unsigned int size, bool openAddressing); // Constructor to initialize the hash table
    ~HashTable(); // Destructor to clean up resources

    bool store(unsigned int id, const std::string& data); // Stores data in the hash table
    int search(unsigned int id, FileBlock*& result) const; // Searches for data by id
    bool remove(unsigned int id); // Removes data by id
    bool corrupt(unsigned int id, const std::string& new_data); // Corrupts data for a given id
    std::string validate(unsigned int id) const; // Validates data for a given id
    std::string printChain(int index) const; // Prints the chain of file blocks at a given index
    void clearTable(); // Clears table entries for re-initialization
};

#endif 