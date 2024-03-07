#ifndef Node_h
#define Node_h

template <class T> class Node
{
public:
    Node();												// constructor
	Node(const T& inpData);										// 
	Node(const T& inpData, Node<T>* nextPtr);
	// ~class Node();												// destructor

	void setData(const T& inpData);
	void setNextPtr(Node<T>* nextPtr);
	T getData() const;
	Node<T>* getNextPtr() const;
private:
	T data;
	Node<T>* next;
	
};

#endif
