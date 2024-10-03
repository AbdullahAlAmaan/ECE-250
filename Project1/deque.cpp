#include "Deque.hpp"
#include <iostream>

Deque::Deque(int init_cap) : capacity(init_cap), size(0), front(0), rear(0) {
    array = new int[capacity];
}

Deque::~Deque() {
    delete[] array;
}

void Deque::resize(int new_capacity) {
    int* new_array = new int[new_capacity];
    int index = 0;
    for (int i = 0; i < size; ++i) {
        new_array[i] = array[(front + i) % capacity];
    }
    delete[] array;
    array = new_array;
    front = 0;
    rear = size;
    capacity = new_capacity;
}

void Deque::push_back(int item) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    array[rear] = item;
    rear = (rear + 1) % capacity;
    size++;
}

int Deque::pop_front() {
    if (is_empty()) {
        return -1; // Error, empty deque
    }
    int result = array[front];
    front = (front + 1) % capacity;
    size--;
    if (size > 0 && size <= capacity / 4) {
        resize(capacity / 2);
    }
    return result;
}

int Deque::pop_back() {
    if (is_empty()) {
        return -1; // Error, empty deque
    }
    rear = (rear - 1 + capacity) % capacity;
    size--;
    if (size > 0 && size <= capacity / 4) {
        resize(capacity / 2);
    }
    return array[rear];
}

int Deque::get_front() const {
    return is_empty() ? -1 : array[front];
}

int Deque::get_back() const {
    return is_empty() ? -1 : array[(rear - 1 + capacity) % capacity];
}

int Deque::get_size() const {
    return size;
}

int Deque::get_capacity() const {
    return capacity;
}

bool Deque::is_empty() const {
    return size == 0;
}
