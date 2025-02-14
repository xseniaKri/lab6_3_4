#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <iostream>

class MyDeque {
private:
    struct Node {
        char data;
        Node* next;
        Node* prev;
        Node(char val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* front;
    Node* back;
    size_t deque_size;

public:
    MyDeque();
    ~MyDeque();

    void push_front(char value);
    void push_back(char value);
    char pop_front();
    char pop_back();
    char front_elem() const;
    char back_elem() const;
    size_t size() const;
    bool is_empty() const;
};

#endif