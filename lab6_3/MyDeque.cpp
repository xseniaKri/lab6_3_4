#include "MyDeque.h"

MyDeque::MyDeque() : front(nullptr), back(nullptr), deque_size(0) {}

MyDeque::~MyDeque() {
    while (!is_empty()) {
        pop_front();
    }
}

void MyDeque::push_front(char value) {
    Node* new_node = new Node(value);
    if (is_empty()) {
        front = back = new_node;
    } else {
        front->prev = new_node;
        new_node->next = front;
        front = new_node;
    }
    deque_size++;
}

void MyDeque::push_back(char value) {
    Node* new_node = new Node(value);
    if (is_empty()) {
        front = back = new_node;
    } else {
        back->next = new_node;
        new_node->prev = back;
        back = new_node;
    }
    deque_size++;
}

char MyDeque::pop_front() {
    if (is_empty()) {
        return '\0'; // Возвращаем символ по умолчанию, если дек пуст
    }
    Node* temp = front;
    char value = temp->data;
    front = front->next;
    if (front) front->prev = nullptr;
    delete temp;
    deque_size--;
    return value;
}

char MyDeque::pop_back() {
    if (is_empty()) {
        return '\0'; // Возвращаем символ по умолчанию, если дек пуст
    }
    Node* temp = back;
    char value = temp->data;
    back = back->prev;
    if (back) back->next = nullptr;
    delete temp;
    deque_size--;
    return value;
}

char MyDeque::front_elem() const {
    return front ? front->data : '\0'; // Возвращаем символ по умолчанию, если дек пуст
}

char MyDeque::back_elem() const {
    return back ? back->data : '\0'; // Возвращаем символ по умолчанию, если дек пуст
}

size_t MyDeque::size() const {
    return deque_size;
}

bool MyDeque::is_empty() const {
    return deque_size == 0;
}