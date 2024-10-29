#pragma once
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <initializer_list>
#include <string>

namespace dll {

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
        void push_back(const T& value);

        /**
         * @brief Метод для добавления элемента в начало списка
         * @param value Значение, которое нужно добавить
         */
        void push_front(const T& value);

        /**
         * @brief Метод для удаления последнего элемента
         * @throws std::out_of_range Если список пуст
         */
        void pop_back();

        /**
         * @brief Метод для удаления первого элемента
         * @throws std::out_of_range Если список пуст
         */
        void pop_front();

        /**
         * @brief Метод для проверки, пустой ли список
         * @return true, если список пуст; false в противном случае
         */
        bool is_empty() const;

        /**
         * @brief Метод для получения строкового представления списка
         * @return Строка, представляющая содержимое списка
         */
        std::string to_string() const;

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
        void clear();
    };

}

namespace dll {

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> values) : DoublyLinkedList() {
        for (const auto& value : values) {
            push_back(value);
        }
    }

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) : DoublyLinkedList() {
        Node<T>* current = other.head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept
        : head(other.head), tail(other.tail), size(other.size) {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    template<typename T>
    DoublyLinkedList<T>::~DoublyLinkedList() {
        clear();
    }

    template<typename T>
    DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            clear();
            Node<T>* current = other.head;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    template<typename T>
    DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            size = other.size;

            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }
        return *this;
    }

    template<typename T>
    void DoublyLinkedList<T>::push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            head = tail = newNode;
        }
        ++size;
    }

    template<typename T>
    void DoublyLinkedList<T>::push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else {
            head = tail = newNode;
        }
        ++size;
    }

    template<typename T>
    void DoublyLinkedList<T>::pop_back() {
        if (is_empty()) throw std::out_of_range("List is empty!");
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr; 
        delete temp;
        --size;
    }

    template<typename T>
    void DoublyLinkedList<T>::pop_front() {
        if (is_empty()) throw std::out_of_range("List is empty!");
        Node<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; 
        delete temp;
        --size;
    }

    template<typename T>
    bool DoublyLinkedList<T>::is_empty() const {
        return size == 0;
    }

    template<typename T>
    std::string DoublyLinkedList<T>::to_string() const {
        std::ostringstream oss;
        oss << "[";
        Node<T>* current = head;
        while (current) {
            oss << current->data;
            current = current->next;
            if (current) oss << ", ";
        }
        oss << "]";
        return oss.str();
    }

    template<typename T>
    void DoublyLinkedList<T>::clear() {
        while (!is_empty()) {
            pop_front();
        }
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list) {
        return out << list.to_string();
    }
}
