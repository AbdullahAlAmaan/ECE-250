#ifndef FILEBLOCK_HPP
#define FILEBLOCK_HPP
#include <string>

// Class representing a block of file data
class FileBlock {
private:
    unsigned int id; // Unique identifier for the file block
    char payload[500]; // Data payload of the file block
    int checksum; // Checksum for data integrity verification

public:
    FileBlock* next; // Pointer for separate chaining in a linked list

    // Default constructor
    FileBlock();

    // Parameterized constructor
    FileBlock(unsigned int id, const std::string& data);
    
    // Clears the payload data
    void clearPayload();

    // Sets the payload data
    void setPayload(const std::string& data);

    // Calculates the checksum of the payload
    int calculateChecksum() const;
    
    // Returns the ID of the file block
    unsigned int getId() const;

    // Returns the checksum of the file block
    int getChecksum() const;

    // Validates the checksum of the payload
    bool validateChecksum() const;

    void corrupt(const std::string& new_data);
};

#endif 
