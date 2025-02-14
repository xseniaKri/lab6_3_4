#include "PointDeque.h"

PointDeque::PointDeque() : front(nullptr), back(nullptr), deque_size(0) {}

PointDeque::~PointDeque() {
    while (!is_empty()) {
        pop_front();
    }
}

void PointDeque::push_front(const Point& value) {
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

void PointDeque::push_back(const Point& value) {
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

Point PointDeque::pop_front() {
    if (is_empty()) {
        return Point(); // Возвращаем точку с нулевыми координатами, если дек пуст
    }
    Node* temp = front;
    Point value = temp->data;
    front = front->next;
    if (front) front->prev = nullptr;
    delete temp;
    deque_size--;
    return value;
}

Point PointDeque::pop_back() {
    if (is_empty()) {
        return Point(); // Возвращаем точку с нулевыми координатами, если дек пуст
    }
    Node* temp = back;
    Point value = temp->data;
    back = back->prev;
    if (back) back->next = nullptr;
    delete temp;
    deque_size--;
    return value;
}

Point PointDeque::front_elem() const {
    return front ? front->data : Point(); // Возвращаем точку с нулевыми координатами, если дек пуст
}

Point PointDeque::back_elem() const {
    return back ? back->data : Point(); // Возвращаем точку с нулевыми координатами, если дек пуст
}

size_t PointDeque::size() const {
    return deque_size;
}

bool PointDeque::is_empty() const {
    return deque_size == 0;
}

void PointDeque::sort_by_polar_angle(const Point& origin) {
    // Сортировка методом пузырька
    for (Node* i = front; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (cross_product(origin, i->data, j->data) < 0) {
                Point temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

Point PointDeque::get_leftmost() const {
    Point leftmost = front_elem();
    Node* current = front;
    while (current) {
        if (current->data.x < leftmost.x) {
            leftmost = current->data;
        }
        current = current->next;
    }
    return leftmost;
}

Point PointDeque::get_second_to_last() const {
    if (deque_size < 2) return Point(); // Возвращаем точку с нулевыми координатами, если точек меньше 2
    Node* current = back;
    return current->prev->data;
}

int PointDeque::cross_product(const Point& a, const Point& b, const Point& c) const {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}