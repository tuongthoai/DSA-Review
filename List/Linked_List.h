#include <algorithm>

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head, *tail;
    int size;

    LinkedList();
    ~LinkedList();

    Node *getNode(int val);
    void push_back(int val);
    void push_front(int val);
    void pop_back();
    void pop_front();
    int search(int val);
    void insert(int pos, int val);
    void erase(int pos);
    void print();
    void sort();
    void sort(Node** head, int sz);
};

LinkedList::LinkedList()
{
    head = tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    Node* p;
    while(head != tail)
    {
        p = head;
        head = head->next;
        delete p;
    }
    delete tail;
    tail = head = nullptr;
}

Node * LinkedList::getNode(int val)
{
    Node* p = new Node;
    if(p == nullptr)
    {
        std::cout << "NOT ENOUGH MEMORY!!!";

        std::exit(0);
    }

    p->data = val;
    p->next = nullptr;
    return p;
}

void LinkedList::push_back(int val)
{
    if(head == nullptr)
    {
        head = tail = getNode(val);
    }
    else
    {
        Node* p = getNode(val);
        tail->next = p;
        tail = p;
    }
    ++size;
}

void LinkedList::push_front(int val)
{
    if(head == nullptr)
    {
        head = tail = getNode(val);
    }
    else
    {
        Node * p = getNode(val);
        p->next = head;
        head = p;
    }
    ++size;
}

void LinkedList::pop_back()
{
    if(tail == nullptr) return;
    Node * p = head;
    for(; p->next->next; p = p->next);
    delete p->next;
    tail = p;
    tail->next = nullptr;
    --size;
}

void LinkedList::pop_front()
{
    if(head == nullptr) return;

    Node * p = head->next;
    delete head;
    head = p;
    --size;
}

void LinkedList::print()
{
    if(head == nullptr) return;
    for(Node* p = head; p; p = p->next) std::cout << p->data << ' ';

    std::cout << std::endl;
}

int LinkedList::search(int val)
{
    if(head == nullptr) return -1;

    int cnt = 0;
    for(Node * p = head; p; p=p->next)
    {
        if(p->data == val) return cnt;

        ++cnt;
    }

    return -1;
}

void LinkedList::insert(int pos, int val)
{
    pos--;
    if(pos < 0 ) 
    {
        push_front(val);
        return;
    }
    if(pos >= size) 
    {
        push_back(val);
        return; 
    }

    Node * tmp = getNode(val);

    int cnt = 0;
    for(Node * p = head; p; p = p->next)
    {
        if(cnt == pos)
        {
            tmp->next = p->next;
            p->next = tmp;
        }

        ++cnt;
    }
}

void LinkedList::erase(int pos)
{
    if(pos <= 0) {pop_front(); return;}
    if(pos >= size) {pop_back(); return;}

    int cnt = 0;
    for(Node* p = head; p->next; p = p->next)
    {
        if(cnt + 1 == pos) 
        {
            Node * tmp = p->next->next;
            delete (p->next);
            p->next = tmp;

            return;
        }
        ++cnt;
    }
}

Node* swap(Node* ptr1, Node* ptr2)
{
    struct Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

//pref: https://www.geeksforgeeks.org/bubble-sort-for-linked-list-by-swapping-nodes/ 
void LinkedList::sort(Node** head, int cnt)
{
    Node** p;
    int ok;
  
    for (int i = 0; i <= cnt; i++)
    {
  
        p = head;
        ok = 0;
  
        for (int j = 0; j < cnt - i - 1; j++) 
        {
  
            Node* p1 = *p;
            Node* p2 = p1->next;
  
            if (p1->data > p2->data)
            {
                *p = swap(p1, p2);
                ok = 1;
            }
  
            p = &((*p)->next);
        }
  
        if (ok == 0)
            break;
    }
}

void LinkedList::sort()
{
    sort(&head, size);
}

LinkedList::LinkedList()
{
    head = tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    Node* p;
    while(head != tail)
    {
        p = head;
        head = head->next;
        delete p;
    }
    delete tail;
    tail = head = nullptr;
}

Node * LinkedList::getNode(int val)
{
    Node* p = new Node;
    if(p == nullptr)
    {
        std::cout << "NOT ENOUGH MEMORY!!!";

        std::exit(0);
    }

    p->data = val;
    p->next = nullptr;
    return p;
}

void LinkedList::push_back(int val)
{
    if(head == nullptr)
    {
        head = tail = getNode(val);
    }
    else
    {
        Node* p = getNode(val);
        tail->next = p;
        tail = p;
    }
    ++size;
}

void LinkedList::push_front(int val)
{
    if(head == nullptr)
    {
        head = tail = getNode(val);
    }
    else
    {
        Node * p = getNode(val);
        p->next = head;
        head = p;
    }
    ++size;
}

void LinkedList::pop_back()
{
    if(tail == nullptr) return;
    Node * p = head;
    for(; p->next->next; p = p->next);
    delete p->next;
    tail = p;
    tail->next = nullptr;
    --size;
}

void LinkedList::pop_front()
{
    if(head == nullptr) return;

    Node * p = head->next;
    delete head;
    head = p;
    --size;
}

void LinkedList::print()
{
    if(head == nullptr) return;
    for(Node* p = head; p; p = p->next) std::cout << p->data << ' ';

    std::cout << std::endl;
}

int LinkedList::search(int val)
{
    if(head == nullptr) return -1;

    int cnt = 0;
    for(Node * p = head; p; p=p->next)
    {
        if(p->data == val) return cnt;

        ++cnt;
    }

    return -1;
}

void LinkedList::insert(int pos, int val)
{
    pos--;
    if(pos < 0 ) 
    {
        push_front(val);
        return;
    }
    if(pos >= size) 
    {
        push_back(val);
        return; 
    }

    Node * tmp = getNode(val);

    int cnt = 0;
    for(Node * p = head; p; p = p->next)
    {
        if(cnt == pos)
        {
            tmp->next = p->next;
            p->next = tmp;
        }

        ++cnt;
    }
}

void LinkedList::erase(int pos)
{
    if(pos <= 0) {pop_front(); return;}
    if(pos >= size) {pop_back(); return;}

    int cnt = 0;
    for(Node* p = head; p->next; p = p->next)
    {
        if(cnt + 1 == pos) 
        {
            Node * tmp = p->next->next;
            delete (p->next);
            p->next = tmp;

            return;
        }
        ++cnt;
    }
}

Node* swap(Node* ptr1, Node* ptr2)
{
    struct Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

//pref: https://www.geeksforgeeks.org/bubble-sort-for-linked-list-by-swapping-nodes/ 
void LinkedList::sort(Node** head, int cnt)
{
    Node** p;
    int ok;
  
    for (int i = 0; i <= cnt; i++)
    {
  
        p = head;
        ok = 0;
  
        for (int j = 0; j < cnt - i - 1; j++) 
        {
  
            Node* p1 = *p;
            Node* p2 = p1->next;
  
            if (p1->data > p2->data)
            {
                *p = swap(p1, p2);
                ok = 1;
            }
  
            p = &((*p)->next);
        }
  
        if (ok == 0)
            break;
    }
}

void LinkedList::sort()
{
    sort(&head, size);
}