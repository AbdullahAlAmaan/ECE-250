#include <iostream>
#include <string>
#include "HashTable.hpp"

int main() {
    HashTable* table = nullptr; // Initialize table to nullptr
    std::string command;
    
    while (std::cin >> command) {
        if (command == "NEW") {
            unsigned int size;
            int method;
            std::cin >> size >> method; 
            delete table; // Delete the existing hash table
            table = new HashTable(size, method == 0); // Create a new hash table
            std::cout << "success\n";
        } else if (command == "STORE") {
            unsigned int id;
            std::string data;
            std::cin >> id >> data;
            if (table && table->store(id, data)) {
                std::cout << "success\n"; // Store the data in the hash table
            } else {
                std::cout << "failure\n"; // Unable to store the data
            }
        } else if (command == "SEARCH") {
    unsigned int id;
    std::cin >> id;
    FileBlock* result = nullptr; 
    int index = table ? table->search(id, result) : -1; // Search for the file block by id
    if (result) {
        std::cout << "found " << id << " in " << index << "\n";
    } else {
        std::cout << "not found\n";
    }
}

 else if (command == "DELETE") {
            unsigned int id;
            std::cin >> id;
            if (table && table->remove(id)) { // Remove the file block by id
                std::cout << "success\n";
            } else {
                std::cout << "failure\n";
            }
        } else if (command == "CORRUPT") {
            unsigned int id;
            std::string data;
            std::cin >> id >> data;
            if (table && table->corrupt(id, data)) { // Corrupt the file block by id
                std::cout << "success\n";
            } else {
                std::cout << "failure\n";
            }
        } else if (command == "VALIDATE") {
            unsigned int id;
            std::cin >> id;
            if (table) {
                std::cout << table->validate(id) << "\n"; // Validate the file block by id
            } else {
                std::cout << "failure\n";
            }
        } else if (command == "PRINT") {
            int index;
            std::cin >> index;
            if (table) {
                std::cout << table->printChain(index) << "\n"; // Print the chain at the given index
            } else { 
                std::cout << "failure\n";
            }
        } else if (command == "EXIT") {
            break;
        }
    }
    delete table; // Delete the hash table
    return 0;
}
