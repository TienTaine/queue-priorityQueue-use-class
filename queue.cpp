#include <iostream>
#include "queue.h"

using namespace std;

template class queue<int>;
template class queue<float>;
template class queue<double>;
template class queue<char>;
template class queue<wchar_t>;
template class queue<bool>;
template class queue<string>;


template <class T> void queue<T>::copyList(const queue<T>& qQueue) 
{
	// Khởi tạo và copy node = head
	Node<T>* node = qQueue.head;
	while (node != NULL)
	{
		//  copy vào cuối với giá trị lấy từ node
		this->tail->getNextPtr() = node;
		this->tail = node;
		// duyệt tới phần tử kế tiếp
		node = node->getNextPtr();
	}
}
// constructor khởi tạo danh sách rỗng 
template <class T>  queue<T> ::queue()
{
	this->head = NULL;
	this->tail = NULL;
}
// copy constructor
template <class T> queue<T> ::queue(const queue <T>& qQueue)
{
	this->head = NULL;
	this->tail = NULL;

	this->copyList(qQueue);
}

// destructor
template <class T> queue<T> :: ~queue()
{
	// xoá danh sách
	this->clear();
}

// độ phức tạp O(1)
template <class T> bool queue<T>::isEmpty() const
{
	return (this->head == NULL);
}

template <class T> void queue<T>::printList() const
{
	Node<T>* node = this->head;
	while (node)
	{
		// in ra giá trị từng node <=> cout << node->data
		cout << node->getData() << " ";
		// duyệt qua node mới
		node = node->getNextPtr();
	}
	cout << endl;
}

// độ phức tạp O(1)	
// thêm phần tử vào đầu queue
template <class T> void queue<T>::enqueue(const T& data)
{
	Node<T>* newNode = new Node<T>(data);
	if (this->isEmpty())
	{
		this->head = newNode;
		this->tail = newNode;
		return;
	}
	this->tail->getNextPtr() = newNode;
	this->tail = newNode;	
}

// độ phức tạp O(1)	
// xoá phần tử ở đầu ( quy tắc FIFO )
template <class T> T queue<T>::dequeue()
{
	if (this->isEmpty())
	{
		return;
	}
	Node<T>* temp = this->head;
	this->head = temp->getNextPtr();
	delete temp;
	if (this->head == NULL)
	{
		this->tail = NULL;
	}
}

// độ phức tạp O(1)	
// lấy ra giá trị đầu của hàng đợi
template <class T> T queue<T>::peek() const
{
	if (!this->isEmpty())
	{
		return this->head->getData();			// <=> node->head->data in ra giá trị node
	}
	else {
		cout << "Hang doi rong\n";
	}
}		

// xoá hàng đợi
// độ phức tạp O(1)	
template <class T> void queue<T>::clear()
{
	Node<T>* temp = this->head;
	while (this->head!= NULL)
	{
		this->head = temp->getNextPtr();
		delete temp;
		temp = this->head;
	}
	this->tail = NULL;
}

// độ phức tạp O(n), vì phải duyệt hết list 
// định nghĩa toán tử = cho 2 queue 
template <class T> queue<T>& queue<T>:: operator=(const queue<T>& qQueue)
{
	if (this != &qQueue)
	{
		if (this->head != NULL)
			this->clear();
		this->copyList(qQueue);
	}
	return*this;
}