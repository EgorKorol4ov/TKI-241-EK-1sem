#include <iostream>
#include "..DoublyLinkedList\DoublyLinkedList.h"

namespace dll
{
    int main() 
    {
        DoublyLinkedList<int> list = { 1, 2, 3, 4 };
        list.PushBack(5);
        list.PushFront(0);
        std::cout << "Содержимое списка: " << list << std::endl;

        list.PopBack();
        std::cout << "После PopBack: " << list << std::endl;

        list.PopFront();
        std::cout << "После PopFront: " << list << std::endl;

        list.Clear();
        std::cout << "После очистки: " << list;

        return 0;
    }
}