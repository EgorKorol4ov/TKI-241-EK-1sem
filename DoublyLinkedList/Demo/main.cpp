#include <iostream>
#include "..DoublyLinkedList\DoublyLinkedList.h"

int main() {
    dll::DoublyLinkedList<int> list = { 1, 2, 3, 4 };
    list.push_back(5);
    list.push_front(0);
    std::cout << "Содержимое списка: " << list << std::endl;

    list.pop_back();
    std::cout << "После pop_back: " << list << std::endl;

    list.pop_front();
    std::cout << "После pop_front: " << list << std::endl;

    list.clear();
    std::cout << "После очистки: " << list

        return 0;
}