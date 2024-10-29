#pragma once
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <initializer_list>
#include <string>

namespace dll {

    /**
     * @brief ���� ����������� ������
     * @tparam T ��� ������, ���������� � ����
     */
    template<typename T>
    class Node {
    public:
        T data;     
        Node* next; 
        Node* prev; 

        /**
         * @brief ����������� ����
         * @param value ��������, ������� ����� ��������� � ����
         */
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    /**
     * @brief ���������� ������
     * @tparam T ��� ������, ���������� � ������
     */
    template<typename T>
    class DoublyLinkedList {
    public:
        /**
         * @brief ����������� �� ���������
         * ������� ������ ���������� ������.
         */
        DoublyLinkedList();

        /**
         * @brief ����������� �������������
         * @param values ������ �������� ��� �������������
         */
        DoublyLinkedList(std::initializer_list<T> values);

        /**
         * @brief ����������� �����������
         * @param other ������ �� ������ ������ DoublyLinkedList, ������� ����� ����������
         */
        DoublyLinkedList(const DoublyLinkedList<T>& other);

        /**
         * @brief ����������� �����������
         * @param other ������ �� ������ ������ DoublyLinkedList, ������� ����� ���������
         */
        DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept;

        /**
         * @brief ����������
         * ������� ������, ���������� ��� ����.
         */
        ~DoublyLinkedList();

        /**
         * @brief �������� ������������
         * @param other ������ �� ������ ������ DoublyLinkedList, ������� ����� ��������
         * @return ������ �� ������� ������
         */
        DoublyLinkedList& operator=(const DoublyLinkedList& other);

        /**
         * @brief �������� �����������
         * @param other ������ �� ������ ������ DoublyLinkedList, ������� ����� ���������
         * @return ������ �� ������� ������
         */
        DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

        /**
         * @brief ����� ��� ���������� �������� � ����� ������
         * @param value ��������, ������� ����� ��������
         */
        void push_back(const T& value);

        /**
         * @brief ����� ��� ���������� �������� � ������ ������
         * @param value ��������, ������� ����� ��������
         */
        void push_front(const T& value);

        /**
         * @brief ����� ��� �������� ���������� ��������
         * @throws std::out_of_range ���� ������ ����
         */
        void pop_back();

        /**
         * @brief ����� ��� �������� ������� ��������
         * @throws std::out_of_range ���� ������ ����
         */
        void pop_front();

        /**
         * @brief ����� ��� ��������, ������ �� ������
         * @return true, ���� ������ ����; false � ��������� ������
         */
        bool is_empty() const;

        /**
         * @brief ����� ��� ��������� ���������� ������������� ������
         * @return ������, �������������� ���������� ������
         */
        std::string to_string() const;

        /**
         * @brief �������� ������ ��� ������ DoublyLinkedList
         * @param out 
         * @param list ������ �� ������ DoublyLinkedList
         * @return �����
         */
        friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list);

    private:
        Node<T>* head; 
        Node<T>* tail; 
        size_t size;   

        /**
         * @brief ����� ��� ������� ������
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
