#ifndef DEQUE_H
#define DEQUE_H

class Deque {
private:
    int* array;          // Dynamic array to hold the deque elements
    int front;           // Index of the front element
    int rear;            // Index of the rear element
    int size;            // Number of elements in the deque
    int capacity;        // Capacity of the deque

    void resize(int new_capacity);  // Resize the array to the new capacity

public:
    Deque(int init_cap = 4);        // Constructor with initial capacity
    ~Deque();                       // Destructor
    void push_back(int item);       // Add an item to the back
    int pop_front();                // Remove and return the front item
    int pop_back();                 // Remove and return the back item
    int get_front() const;          // Get the front item
    int get_back() const;           // Get the back item
    int get_size() const;           // Get the number of elements
    int get_capacity() const;       // Get the capacity of the deque
    bool is_empty() const;          // Check if the deque is empty
};

#endif
