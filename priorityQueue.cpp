#include <iostream>
#include "priorityQueue.h"

using namespace std;

template class priorityQueue<int>;
template class priorityQueue<float>;
template class priorityQueue<double>;
template class priorityQueue<char>;
template class priorityQueue<wchar_t>;
template class priorityQueue<bool>;
template class priorityQueue<string>;

void swap(int& x, int& y)
{
    int& temp = x;
    x = y;
    y = temp;
}

// constructor
template <class T>  priorityQueue<T> ::priorityQueue()
{
	*arr = new int[MAXSIZE +1];
    heapSize = 0;
}

// destructor
template <class T> priorityQueue<T> :: ~priorityQueue()
{
    
}

// kiểm tra hàng đợi có rỗng k 
// O(1)
template <class T> bool priorityQueue<T>::isEmpty() const
{
    return heapSize = 0; 
}

// thêm 1 phần tử vào hàng đợi => thêm phần tử vào là sắp xếp vào theo thứ tự tăng dần
// O(logn)
template <class T> void priorityQueue<T>::push(const T& data)
{
    heapSize++;                                                     // tăng số lượng phần tử của mảng
    arr[heapSize] = data;                                           // gán vị trí mới đó giá trị = data 
    int current = heapSize;                                         // gọi 1 biến current tại vị trí mới thêm vào
    int parent = current / 2;                                       // tìm vị trí nút "ba" của vị trí current
    while (parent != 0 && arr[parent] > arr[current])                 // chạy vòng lặp và sắp xếp giá trị tại vị trí current vào vị trí mới với độ ưu tiên thích hợp
    {
        swap(arr[parent], arr[current]);                            // swap 2 giá trị
        current = parent;                                           // swap vị trí
        parent = current / 2;                                       // tiếp tục tìm nút "ba" 
    }

}
// O(logn)
template <class T> void priorityQueue<T>::pop()
{
    // check xem hàng đợi có rỗng k
    if (isEmpty())
    {
        cout << "Hang doi rong!" << endl;
        return;
    }
    int minRoot = arr[1];
    arr[1] = arr[heapSize];
    heapSize--;
    int current = 1;
    
    while ((2 * current) <= heapSize)
    {
        int leftChild = 2 * current;                                             // gán vị trí cây con bên trái của current
        int rightChild = leftChild + 1;                                          // vị trí cây con bên phải của current
        int smallerChild = leftChild;                                            // gán 1 biến smaller tạm = vị trí cây con bên trái
        if (rightChild <= heapSize && arr[rightChild] < arr[leftChild])
        {   
            smallerChild = rightChild;
        }
        if (arr[current] > arr[smallerChild])
        {
            swap(arr[current], arr[smallerChild]);
            current = smallerChild;
        }
        else break; 
    }
}
// trả về giá trị ưu tiên nhỏ nhất
// O(1)
template <class T> T priorityQueue<T>::getMin() const
{
    // vì đây là cây minHeap nên giá trị nhỏ nhất sẽ là giá trị đầu tiên
    return arr[1];
}
