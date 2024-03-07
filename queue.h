#ifndef queue_h
#define queue_h
#include "Node.h"

template <class T> class queue {
protected:
    Node<T>* head;
    Node<T>* tail;
    void copyList(const queue<T>&);
public:
    queue();                                       // constructor
    queue(const queue&);                           // sao chép constructor
    ~queue();                              // destructor

    void printList() const;                     // in danh sách

    bool isEmpty() const;                        // check danh sách có rỗng k
    void enqueue(const T&);                     // thêm
     T dequeue();                                // xoá 
     T peek() const;                             // lấy ra giá trị đầu
    void clear();                                // xoá danh sách

    queue<T>& operator=(const queue<T>&);   // định nghĩa toán tử = của 2 danh sách
};
#endif