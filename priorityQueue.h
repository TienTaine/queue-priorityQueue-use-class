#ifndef priorityQueue_h
#define priorityQueue_h
#include "Node.h"
#define MAXSiZE 100 
template <class T> class priorityQueue {
private:
    int* arr;
    int heapSize = 0;
public:
    priorityQueue();                                // constructor
    priorityQueue(const priorityQueue &);           // copy constructor
    ~priorityQueue();                               // destructor

    bool isEmpty() const;                           // check empty
    T getMin() const;                               // lấy ra giá trị nhỏ nhất trong hàng đợi
    void push(const T&);                            // thêm vào phần tử
    void pop();                                     // xoá đi phần tử
    priorityQueue<T>& operator=(const priorityQueue<T>&);       // định nghĩa toán tử để so sánh 2 hàng đợi
};
#endif // !priorityQueue_h
