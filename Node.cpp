#include <iostream>
#include "Node.h"

template class Node<int>; 
template class Node<float>;
template class Node<double>;
//template class Node<char>;    
//template class Node<wchar_t>;
////template class Node<bool>;
////template class Node<std::string>;

template <class T> Node<T>::Node() {
    // khởi tạo
    this->next = nullptr;
}

template <class T> Node<T>::Node(const T& inpData) {
    // tạo 1 node mới
    this->data = inpData;
    this->next = nullptr;
}

template <class T> Node<T>::Node(const T& inpData, Node<T>* nextPtr) {
    this->data = inpData;
    this->next = nextPtr;
}

template <class T> void Node<T>::setData(const T& inpData) {
    // set giá trị tại node
    this->data = inpData;

}


template <class T> void Node<T>::setNextPtr(Node<T>* nextPtr) {
    
    this->next = nextPtr;
 
}

template <class T> T Node<T>::getData() const {
    // trả về giá trị tại node
    return this->data;
}

template <class T> Node<T>* Node<T>::getNextPtr() const {
    // duyệt tới node tiếp theo
    return this->next;
}