#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template<typename T>
class Stack
{
public:
    Node<T> *head, *tail;
    int size;

    Stack();
    ~Stack();

    Node<T> *getNode(T val);
    void push_back(T val);
    void pop_back();
    T back();
    int getSize();
    void print();
};

template<typename T>
Stack<T>::Stack()
{
    head = tail = nullptr;
    size = 0;
}

template<typename T>
Stack<T>::~Stack()
{
    Node<T> * p;
    while(head != tail)
    {
        p = head;
        head = head->next;
        delete p;
    }
    delete tail;
    tail = head = nullptr;
    size = 0;
}

template<typename T>
Node<T> * Stack<T>::getNode(T val)
{
    Node<T>* p = new Node<T>;
    if(p == nullptr)
    {
        std::cout << "NOT ENOUGH MEMORY!!!";

        std::exit(0);
    }

    p->data = val;
    p->next = nullptr;
    return p;
}

template<typename T>
void Stack<T>::push_back(T val)
{
    if(head == nullptr)
    {
        head = tail = getNode(val);
    }
    else
    {
        Node<T>* p = getNode(val);
        tail->next = p;
        tail = p;
    }
    ++size;
}

template<typename T>
void Stack<T>::pop_back()
{
    if(head == nullptr) return;
    if(head->next == nullptr) 
    {
        delete head;
        head = tail = nullptr;
        --size;
        return;
    }

    if(tail == nullptr) return;
    if(size == 1) 
    {
        Stack<T>::pop_front();
        --size;
    }
    Node<T> *p = head;
    for(; p->next->next; p = p->next);
    delete p->next;
    tail = p;
    tail->next = nullptr;
    --size;
}

template<typename T>
void Stack<T>::print()
{
    if(head == nullptr) return;
    for(Node<T>* p = head; p; p = p->next) std::cout << p->data << ' ';

    std::cout << std::endl;
}

template<typename T>
T Stack<T>::back()
{
    if(tail!=nullptr) return tail->data;
}

template<typename T>
int Stack<T>::getSize()
{
    return this->size * sizeof(Node<T>);
}
