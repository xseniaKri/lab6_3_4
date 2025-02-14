#ifndef POINTDEQUE_H
#define POINTDEQUE_H

struct Point {
    int x, y;
    Point(int px = 0, int py = 0) : x(px), y(py) {}
};

class PointDeque {
private:
    struct Node {
        Point data;
        Node* next;
        Node* prev;
        Node(Point val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* front;
    Node* back;
    size_t deque_size;

public:
    PointDeque();
    ~PointDeque();

    void push_back(const Point& value);
    Point pop_front();
    Point pop_back();
    Point front_elem() const;
    Point back_elem() const;
    size_t size() const;
    bool is_empty() const;
    void sort_by_polar_angle(const Point& origin);
    Point get_leftmost() const;
    Point get_second_to_last() const;
    int cross_product(const Point& a, const Point& b, const Point& c) const;
};

#endif 