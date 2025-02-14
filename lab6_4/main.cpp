#include <iostream>
#include <string>

#include "MyDeque.h"
#include "PointDeque.h"
#pragma comment(lib, "Deques.lib")
using namespace std;


// Функция для проверки, является ли строка палиндромом
bool is_palindrome(string str) {
    MyDeque deque; // Создаем экземпляр дека для хранения символов строки
    
    // Заполняем дек символами строки
    for (char ch : str) {
        deque.push_back(ch);
    }
    
    // Пока в деке больше одного символа, сравниваем первый и последний
    while (deque.size() > 1) {
        if (deque.pop_front() != deque.pop_back()) {
            return false; // Если символы не совпадают, строка не является палиндромом
        }
    }
    return true; // Если все символы совпали, строка - палиндром
}

// Функция для построения выпуклой оболочки методом Грэхема
void convex_hull(PointDeque& points) {
    if (points.size() < 3) { // Проверяем, достаточно ли точек для построения оболочки
        cout << "Not enough points to form a convex hull." << endl;
        return;
    }
    
    // Находим самую левую точку
    Point start = points.get_leftmost();
    
    // Сортируем точки по полярному углу относительно самой левой точки
    points.sort_by_polar_angle(start);
    
    PointDeque hull; // Дек для хранения точек выпуклой оболочки
    hull.push_back(points.pop_front()); // Добавляем первую точку
    hull.push_back(points.pop_front()); // Добавляем вторую точку
    
    while (!points.is_empty()) {
        Point top = hull.pop_back(); // Берем последнюю точку оболочки
        
        // Проверяем направление поворота (удаляем точки, образующие правый поворот)
        while (!hull.is_empty()) {
            Point A = hull.get_second_to_last();
            Point B = top;
            Point C = points.front_elem();
            
            // Вычисляем векторное произведение
            int cross_product = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
            
            if (cross_product > 0) {
                break; // Если поворот левый, прекращаем удаление точек
            }
            top = hull.pop_back(); // Удаляем точку из оболочки
        }
        
        hull.push_back(top); // Добавляем точку обратно
        hull.push_back(points.pop_front()); // Добавляем новую точку
    }
    
    // Выводим точки выпуклой оболочки
    cout << "Convex hull points:" << endl;
    while (!hull.is_empty()) {
        Point p = hull.pop_front();
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}

int main() {
    int choice;
    cout << "Choose a task: 1 - Check palindrome, 2 - Convex hull" << endl;
    cin >> choice;
    
    if (choice == 1) {
        cout << "Enter a string: ";
        string input;
        cin >> input;
        
        // Проверяем, является ли строка палиндромом
        if (is_palindrome(input)) {
            cout << "The string is a palindrome." << endl;
        } else {
            cout << "The string is not a palindrome." << endl;
        }
    } else if (choice == 2) {
        cout << "Enter the number of points: ";
        int n;
        cin >> n;
        
        PointDeque points; // Дек для хранения точек
        
        // Считываем координаты точек и добавляем их в дек
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            points.push_back(Point(x, y));
        }
        
        // Вызываем функцию построения выпуклой оболочки
        convex_hull(points);
    } else {
        cout << "Invalid choice." << endl;
    }
    return 0;
}