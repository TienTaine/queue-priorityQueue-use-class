#ifndef stack_h
#define stack_h

#include "Node.h"

template <class T> class stack {
protected:
    Node<T>* head;
    void copyList(const stack<T>&);
public:
    stack();                                       // constructor
    stack(const stack&);                           // sao chép constructor
    ~stack();                                     // destructor

    bool isEmpty() const;                               // check danh sách có rỗng k

    void push(const T&);                        // thêm node ở top
    void pop();                                 // xoá node top
    T topValue() const;                         // lấy ra giá trị của top
    void clear();                                       // xoá danh sách

    stack<T>& operator=(const stack<T>&);   // định nghĩa toán tử = của 2 danh sách
};

#endif 