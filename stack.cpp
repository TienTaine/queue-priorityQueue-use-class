#include <iostream>
#include "stack.h"

using namespace std;

template class stack<int>;
template class stack<float>;
template class stack<double>;
//template class stack<char>;
//template class stack<wchar_t>;

template <class T> void stack<T>::copyList(const stack<T>& sStack)
{
	// Khởi tạo và copy node = head
	Node<T>* node = sStack.head;
	while (node != NULL)
	{
		//  copy vào cuối với giá trị lấy từ node
		this->tail->getNextPtr() = node;
		this->tail = node;
		// duyệt tới phần tử kế tiếp
		node = node->getNextPtr();
	}
}
// khởi tạo danh sách rỗng
template <class T>  stack<T> ::stack()
{
	this->head = NULL;
}

// copy constructor
template <class T> stack<T> ::stack(const stack <T>& sStack)
{
	this->head = NULL;
	this->copyList(sStack);
}

// destructor
template <class T> stack<T> :: ~stack()
{
	// xoá danh sách
	this->clear();
}

// kiểm tra danh sách có rỗng k
// độ phức tạp O(1)
template <class T> bool stack<T> ::isEmpty() const
{
	return (this->head == NULL);
}

// thêm node vào stack
// độ phức tạp O(1)
template <class T> void stack<T> ::push(const T& data)
{
	Node<T>* newNode = new Node<T>(data);
	if (this->head != NULL)
	{
		this->head = newNode;
	}
	else
	{
		newNode->getNextPtr() = this->head;
		this->head = newNode;
	}
}

// lấy phần tử top ra
// độ phức tạp O(1)
template <class T> void stack<T> ::pop()
{
	if (!this->isEmpty())
	{
		 Node<T>* temp = this->head;
		this->head = temp->getNextPtr();
		delete temp;
	}
}

// Lấy ra giá trị top
// độ phức tạp O(1)
template <class T> T stack<T> ::topValue() const
{
	if (!this->isEmpty())
	{
		return this->head->getData();
	}
}

// xoá stack
// độ phức tạp O(n)
template <class T> void stack<T> ::clear()
{
	Node<T>* temp = this->head;
	// duyệt ds và xoá từng head
	while (temp != NULL)
	{
		Node<T>* tmp = temp;
		temp = temp->next;
		delete tmp;
	}
	this->head = NULL;
}

// định nghĩa toán tử = cho 2 stack
template <class T> stack<T> & stack<T>:: operator=(const stack<T>& sStack)
{
	if (this != &sStack)
	{
		if (this->head != NULL)
			this->clear();
		this->copyList(sStack);
	}
	return* this;
}
