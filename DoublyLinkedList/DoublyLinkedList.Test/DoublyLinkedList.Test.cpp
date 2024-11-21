#include "pch.h"
#include "CppUnitTest.h"
#include "../DoublyLinkedList/DoublyLinkedList.h"
#include "../DoublyLinkedList/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace dll
{
	TEST_CLASS(DoublyLinkedListTest)
	{
	public:
		
        TEST_METHOD(IsEmpty_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<int> list{};
            // Act
            bool isEmpty = list.IsEmpty();
            // Assert
            Assert::IsTrue(isEmpty);
        }
        TEST_METHOD(IsEmptyStr_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<std::string> list{};
            // Act
            bool isEmpty = list.IsEmpty();
            // Assert
            Assert::IsTrue(isEmpty);
        }
        TEST_METHOD(IsEmptyPoint_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<Point> list{};
            // Act
            bool isEmpty = list.IsEmpty();
            // Assert
            Assert::IsTrue(isEmpty);
        }
        TEST_METHOD(PushBackInt_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<int> list{ 1, 2, 3 };
            std::string expected = "1, 2, 3, 5";
            // Act
            list.PushBack(5);
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(PushBackStr_ValidData_Success) 
        {
            // Arrange
            DoublyLinkedList<std::string> list;
            std::string expected = "Hello, World";
            // Act
            list.PushBack("Hello");
            list.PushBack("World");
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(PushBackPoint_ValidData_Success)
        {
            // Arrange
            Point point1(1, 1);
            Point point2(1, 2);
            Point point3(1, 3);
            DoublyLinkedList<Point> list{ point1, point2 };
            std::string expected = "1 1, 1 2, 1 3";
            // Act
            list.PushBack(point3);
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(PushFrontInt_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<int> list;
            std::string expected = "1, 2, 3";
            // Act
            list.PushFront(3);
            list.PushFront(2);
            list.PushFront(1);
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(PushFrontStr_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<std::string> list;
            std::string expected = "Hello, World";
            // Act
            list.PushFront("World");
            list.PushFront("Hello");
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(PushFrontPoint_ValidData_Success)
        {
            // Arrange
            Point point1(1, 1);
            Point point2(1, 2);
            Point point3(1, 3);
            DoublyLinkedList<Point> list;
            std::string expected = "1 3, 1 1, 1 2";
            // Act
            list.PushFront(point2);
            list.PushFront(point1);
            list.PushFront(point3);
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(PopBackInt_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<int> list{ 1, 5, 8, 7 };
            std::string expected = "1, 5, 8";
            // Act
            list.PopBack();
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(PopBackStr_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList <std::string> list{ "Hello", "World" };
            std::string expected = "Hello";
            // Act
            list.PopBack();
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(PopBackPoint_ValidData_Success)
        {
            // Arrange
            Point point1(1, 1);
            Point point2(1, 2);
            Point point3(1, 3);
            DoublyLinkedList<Point> list{ point1, point2, point3 };
            std::string expected = "1 1, 1 2";
            // Act
            list.PopBack();
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(PopFrontInt_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<int> list{ 1, 5, 8, 7 };
            std::string expected = "5, 8, 7";
            // Act
            list.PopFront();
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(PopFrontStr_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList <std::string> list{ "Hello", "World" };
            std::string expected = "World";
            // Act
            list.PopBack();
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(PopFrontPoint_ValidData_Success)
        {
            // Arrange
            Point point1(1, 1);
            Point point2(1, 2);
            Point point3(1, 3);
            DoublyLinkedList<Point> list{ point1, point2, point3 };
            std::string expected = "1 2, 1 3";
            // Act
            list.PopFront();
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(InsertInt_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<int> list{ 1, 5, 8, 7 };
            std::string expected = "1, 5, 3, 8, 7";
            // Act
            list.Insert(2,3);
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(InsertStr_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<std::string> list{ "Hello", "World" };
            std::string expected = "Hello, My, World";
            // Act
            list.Insert(1, "My");
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(InsertPoint_ValidData_Success)
        {
            // Arrange
            Point point1(1, 1);
            Point point2(1, 2);
            Point point3(1, 3);
            DoublyLinkedList<Point> list{ point1, point2};
            std::string expected = "1 1, 1 3, 1 2";
            // Act
            list.Insert(1, point3);
            std::string actual = list.ToString();
            // Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(InsertInt_IncorrectData_Success)
        {
            // Arrange
            DoublyLinkedList<int> list{ 1, 5, 8, 7 };
            // Act & Assert
            Assert::ExpectException<std::out_of_range>([&]() { list.Insert(10, 4); });
        }
        TEST_METHOD(InsertStr_IncorrectData_Success)
        {
            // Arrange
            DoublyLinkedList<std::string> list{ "Hello" , "World"};
            // Act & Assert
            Assert::ExpectException<std::out_of_range>([&]() { list.Insert(10, "My"); });
        }
        TEST_METHOD(ToStringInt_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<int> list{ 1, 5, 8, 7 };
            std::string expected = "1, 5, 8, 7";
            //Act
            std::string actual = list.ToString();
            //Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(ToStringInt_ValidData_Success)
        {
            // Arrange
            DoublyLinkedList<std::string> list{ "Hello", "World" };
            std::string expected = "Hello, World";
            //Act
            std::string actual = list.ToString();
            //Assert
            Assert::AreEqual(expected, actual);
        }
        TEST_METHOD(ToStringPoint_ValidData_Success)
        {
            // Arrange
            Point point1(1, 1);
            Point point2(1, 2);
            Point point3(1, 3);
            DoublyLinkedList<Point> list{ point1, point2, point3 };
            std::string expected = "1 1, 1 2, 1 3";
            //Act
            std::string actual = list.ToString();
            //Assert
            Assert::AreEqual(expected, actual);
        }
	};
}
