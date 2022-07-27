#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template<typename T>
class Queue
{
public:
    Node<T> *head, *tail;
    int size;

    Queue();
    ~Queue();

    Node<T> *getNode(T val);
    void push(T val);
    void pop();
    T front();
    int getSize();
    void print();
};

template<typename T>
Queue<T>::Queue()
{
    head = tail = nullptr;
    size = 0;
}

template<typename T>
Queue<T>::~Queue()
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
Node<T> * Queue<T>::getNode(T val)
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
void Queue<T>::push(T val)
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
void Queue<T>::pop()
{
    if(head == nullptr) return;

    Node<T> * p = head->next;
    delete head;
    head = p;
    --size;
}

template<typename T>
void Queue<T>::print()
{
    if(head == nullptr) return;
    for(Node<T>* p = head; p; p = p->next) std::cout << p->data << ' ';

    std::cout << std::endl;
}

template<typename T>
T Queue<T>::front()
{
    if(head!=nullptr) return head->data;
}

template<typename T>
int Queue<T>::getSize()
{
    return this->size * sizeof(Node<T>);
}