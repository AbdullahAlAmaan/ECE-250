#include "FileBlock.hpp"

FileBlock::FileBlock() : id(0), checksum(0), next(nullptr) { // Default constructor
    clearPayload(); // Initialize payload to zero
}

FileBlock::FileBlock(unsigned int id, const std::string& data) : id(id), next(nullptr) { // Parameterized constructor
    clearPayload(); // Initialize payload to zero
    setPayload(data); // Set payload data
    checksum = calculateChecksum(); // Calculate and set checksum
}

void FileBlock::clearPayload() {
    for (int i = 0; i < 500; ++i) {
        payload[i] = 0; // Clear payload data
    }
}

void FileBlock::setPayload(const std::string& data) {
    for (size_t i = 0; i < data.length() && i < 500; ++i) {
        payload[i] = data[i]; // Set payload data
    }
}

int FileBlock::calculateChecksum() const {
    int sum = 0;
    for (int i = 0; i < 500; ++i) {
        sum += static_cast<unsigned char>(payload[i]);  // Calculate sum of payload data
    }
    return sum % 256; // Return checksum
}

unsigned int FileBlock::getId() const {
    return id; // Return file block ID
}

int FileBlock::getChecksum() const {
    return checksum; // Return checksum
}

bool FileBlock::validateChecksum() const {
    return checksum == calculateChecksum(); // Validate checksum
}

void FileBlock::corrupt(const std::string& new_data) {
    clearPayload(); // Clear existing payload
    setPayload(new_data); // Set new payload data
}