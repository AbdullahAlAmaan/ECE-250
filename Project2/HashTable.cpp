#include "HashTable.hpp"
#include <iostream>

HashTable::HashTable(unsigned int size, bool openAddressing) : size(size), useOpenAddressing(openAddressing) {
    table = new FileBlock*[size]; // Allocate memory for the table
    for (unsigned int i = 0; i < size; ++i) {
        table[i] = nullptr; // Initialize all entries to nullptr
    }
}

HashTable::~HashTable() {
    clearTable(); 
    delete[] table; // Deallocate memory for the table
}

void HashTable::clearTable() { // Clear table entries for re-initialization
    for (unsigned int i = 0; i < size; ++i) { 
        FileBlock* current = table[i];   
        while (current != nullptr) {   
            FileBlock* toDelete = current; 
            current = current->next; 
            delete toDelete;
        }
        table[i] = nullptr; 
    }
}

int HashTable::primaryHash(unsigned int key) const {
    return key % size; // Simple primary hash
} 

int HashTable::secondaryHash(unsigned int key) const {
    int hash = (key / size) % size; // Secondary hash based on division
    return (hash % 2 == 0) ? hash + 1 : hash;  // Ensure step size is odd
}

bool HashTable::store(unsigned int id, const std::string& data) {
    int hash = primaryHash(id); // Calculate primary hash
    if (useOpenAddressing) { 
        int step = secondaryHash(id); // Calculate secondary hash
        for (int i = 0; i < size; ++i) {
            int index = (hash + i * step) % size; // Calculate index
            if (table[index] == nullptr || table[index]->getId() == 0) { // Empty slot or corrupted
                delete table[index]; // Delete existing block
                table[index] = new FileBlock(id, data); // Create new block
                return true;
            }
        }
    } else { // Separate chaining
        FileBlock* newBlock = new FileBlock(id, data); // Create new block
        if (table[hash] == nullptr) { 
            table[hash] = newBlock; // Insert at the beginning
        } else {
            FileBlock* current = table[hash]; 
            FileBlock* prev = nullptr; 
            while (current && current->getId() < id) {
                prev = current;
                current = current->next;
            }
            if (current && current->getId() == id) { // ID already exists
                delete newBlock;
                return false;
            }
            if (prev == nullptr) { // Insert at the beginning
                newBlock->next = table[hash];
                table[hash] = newBlock;
            } else { // Insert in the middle or end
                newBlock->next = current;
                prev->next = newBlock;
            }
        }
        return true;
    }
    return false;
}

int HashTable::search(unsigned int id, FileBlock*& result) const {
    int hash = primaryHash(id);
    if (useOpenAddressing) { 
        int step = secondaryHash(id); 
        for (int i = 0; i < size; ++i) {  
            int index = (hash + i * step) % size; // Calculate index
            if (table[index] && table[index]->getId() == id) {   
                result = table[index]; // Set result to the found block
                return index; 
            }
        }
    } else { // Separate chaining
        FileBlock* current = table[hash]; 
        while (current) { 
            if (current->getId() == id) { 
                result = current;
                return hash;
            }
            current = current->next; // Traverse the linked list
        }
    }
    result = nullptr;
    return -1; // Not found
}
bool HashTable::remove(unsigned int id) {
    int hash = primaryHash(id);

    if (useOpenAddressing) {
        int step = secondaryHash(id);
        for (int i = 0; i < size; ++i) {
            int index = (hash + i * step) % size;
            if (table[index] && table[index]->getId() == id) { 
                delete table[index]; // Delete block
                table[index] = nullptr; // Set to nullptr to avoid dangling pointer
                return true;
            }
        }
    } else { // Separate chaining
        FileBlock* current = table[hash]; 
        FileBlock* prev = nullptr;  
        while (current) {
            if (current->getId() == id) {
                if (prev == nullptr) {
                    table[hash] = current->next; // Remove from the beginning
                } else {
                    prev->next = current->next; // Remove from the middle or end
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
    }
    return false;
}


bool HashTable::corrupt(unsigned int id, const std::string& new_data) {
    FileBlock* block = nullptr;
    int index = search(id, block);

    if (index != -1) { // Check if the block was found
        block->corrupt(new_data); 
        return true;
    }
    return false;
}

std::string HashTable::validate(unsigned int id) const {
    FileBlock* block = nullptr;
    int index = search(id, block); 

    if (index != -1) { // Check if the block was found
        return block->validateChecksum() ? "valid" : "invalid"; 
    }
    return "failure";
}

std::string HashTable::printChain(int index) const {
    if (table[index] == nullptr) {
        return "chain is empty";
    }
    FileBlock* current = table[index]; 
    std::string result;
    while (current) {   
        result += std::to_string(current->getId()) + " ";  
        current = current->next; 
    }
    return result;  
}
