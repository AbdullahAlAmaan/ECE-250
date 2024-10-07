#ifndef DEQUE_H
#define DEQUE_H

class Deque {
private:
    int* array;          
    int front;           
    int rear;            
    int size;            
    int capacity;        

    void resize(int new_capacity);  

public:
    Deque(int init_cap = 4);       
    ~Deque();                       
    void push_back(int item);       
    int pop_front();               
    int pop_back();                 
    int get_front() const;          
    int get_back() const;           
    int get_size() const;           
    int get_capacity() const;       
    bool is_empty() const;          
};

#endif
