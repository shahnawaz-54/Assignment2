#include <iostream>
#include "SingleLinkedList.h"

int main() {
    SingleLinkedList<int> list;

    // Test push_front and push_back
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);

    // Test front and back
    std::cout << "Front: " << list.front() << "\n"; // Expected: 20
    std::cout << "Back: " << list.back() << "\n";   // Expected: 30

    // Test size
    std::cout << "Size: " << list.size() << "\n";   // Expected: 3

    // Test pop_front
    list.pop_front();
    std::cout << "Front after pop_front: " << list.front() << "\n"; // Expected: 10

    // Test insert
    list.insert(1, 40);
    std::cout << "Front: " << list.front() << "\n"; // Expected: 10
    std::cout << "Back: " << list.back() << "\n";   // Expected: 30

    // Test remove
    list.remove(1);
    std::cout << "After remove: " << list.size() << "\n"; // Expected: 2

    return 0;
} 
