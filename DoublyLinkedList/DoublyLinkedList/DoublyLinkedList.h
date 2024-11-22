#pragma once
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <initializer_list>
#include <string>

namespace dll 
{

    /**
     * @brief Узел двусвязного списка
     * @tparam T Тип данных, хранящихся в узле
     */
    template<typename T>
    class Node {
    public:
        T data;     
        Node* next; 
        Node* prev; 

        /**
         * @brief Конструктор узла
         * @param value Значение, которое будет храниться в узле
         */
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    /**
     * @brief Двусвязный список
     * @tparam T Тип данных, хранящихся в списке
     */
    template<typename T>
    class DoublyLinkedList {
    public:
        /**
         * @brief Конструктор по умолчанию
         * Создает пустой двусвязный список.
         */
        DoublyLinkedList();

        /**
         * @brief Конструктор инициализации
         * @param values Список значений для инициализации
         */
        DoublyLinkedList(std::initializer_list<T> values);

        /**
         * @brief Конструктор копирования
         * @param other Ссылка на другой объект DoublyLinkedList, который будет скопирован
         */
        DoublyLinkedList(const DoublyLinkedList<T>& other);

        /**
         * @brief Конструктор перемещения
         * @param other Ссылка на другой объект DoublyLinkedList, который будет перемещен
         */
        DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept;

        /**
         * @brief Деструктор
         * Очищает память, освобождая все узлы.
         */
        ~DoublyLinkedList();

        /**
         * @brief Обмен содержимым.
         * @param other Обмениваемый список.
        */
        void Swap(DoublyLinkedList<T>& other) noexcept;

        /**
         * @brief Оператор присваивания
         * @param other Ссылка на другой объект DoublyLinkedList, который будет присвоен
         * @return Ссылка на текущий объект
         */
        DoublyLinkedList& operator=(const DoublyLinkedList& other);

        /**
         * @brief Оператор перемещения
         * @param other Ссылка на другой объект DoublyLinkedList, который будет перемещен
         * @return Ссылка на текущий объект
         */
        DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

        /**
         * @brief Метод для добавления элемента в конец списка
         * @param value Значение, которое нужно добавить
         */
        void PushBack(const T& value);

        /**
         * @brief Метод для добавления элемента в начало списка
         * @param value Значение, которое нужно добавить
         */
        void PushFront(const T& value);

        /**
         * @brief Метод для удаления последнего элемента
         * @throws std::out_of_range Если список пуст
         */
        void PopBack();

        /**
         * @brief Вставка элемента по индексу
         * @param index Позиция для вставки элемента
         * @param value Значение элемента
         */
        void Insert(size_t index, const T& value);

        /**
         * @brief Метод для удаления первого элемента
         * @throws std::out_of_range Если список пуст
         */
        void PopFront();

        /**
         * @brief Метод для проверки, пустой ли список
         * @return true, если список пуст; false в противном случае
         */
        bool IsEmpty() const;

        /**
         * @brief Метод для получения строкового представления списка
         * @return Строка, представляющая содержимое списка
         */
        std::string ToString() const;

        /**
         * @brief Оператор вывода для класса DoublyLinkedList
         * @param out 
         * @param list Ссылка на объект DoublyLinkedList
         * @return Вывод
         */
        friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list);

    private:
        Node<T>* head; 
        Node<T>* tail; 
        size_t size;   

        /**
         * @brief Метод для очистки списка
         */
        void Clear();
    };

}

namespace dll {

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> values) : DoublyLinkedList() {
        for (const auto& value : values) 
        {
            PushBack(value);
        }
    }

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) : DoublyLinkedList() {
        Node<T>* current = other.head;
        while (current) 
        {
            PushBack(current->data);
            current = current->next;
        }
    }

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept
        : head(other.head), tail(other.tail), size(other.size) 
    {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    template<typename T>
    DoublyLinkedList<T>::~DoublyLinkedList() 
    {
        Clear();
    }

    template<typename T>
    inline void DoublyLinkedList<T>::Swap(DoublyLinkedList<T>& other) noexcept
    {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
    }

    template<typename T>
    DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& other) {
        if (this != &other) 
        {
            DoublyLinkedList<T> temp(other);
            this->Swap(temp);
        }
        return *this;
    }

    template<typename T>
    DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList&& other) noexcept {
        if (this != &other)
            {
                this->Swap(other);
            }
        return *this;
    }

    template<typename T>
    void DoublyLinkedList<T>::PushBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) 
        {
            head = newNode;
        }
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::PushFront(const T& value) 
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::PopBack() 
    {
        if (tail == nullptr)
        {
            return;
        }
        if (head == tail)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::PopFront() 
    {
        if (head == nullptr)
        {
            return;
        }
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::Insert(size_t index, const T& value) 
    {
        if (index > size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0) 
        {
            PushFront(value);
            return;
        }
        if (index == size) 
        {
            PushBack(value);
            return;
        }
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i)
        {
            current = current->next;
        }
        Node<T>* newNode = new Node<T>(value);
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) 
        {
            current->prev->next = newNode;
        }
        current->prev = newNode;
        ++size;
    }

    template<typename T>
    bool DoublyLinkedList<T>::IsEmpty() const 
    {
        return head == nullptr;
    }

    template<typename T>
    std::string DoublyLinkedList<T>::ToString() const 
    {
        std::ostringstream oss;
        Node<T>* current = head;
        while (current != nullptr) 
        {
            oss << current->data;
            current = current->next;
            if (current->next != nullptr) 
            { 
                oss << ", "; 
            }
            current = current->next;
        }
        return oss.str();
    }

    template<typename T>
    void DoublyLinkedList<T>::Clear() 
    {
        while (!IsEmpty()) 
        {
            PopFront();
        }
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list) 
    {
        return out << list.ToString();
    }
}
