#include <algorithm>
template <typename T>
struct Node
{
    int height;
    T data;
    Node<T> *left, *right;
    Node<T>(T data)
    {
        this->data = data;
        this->height = 1;
        left = right = nullptr;
    }
};

template <typename T>
class AVL
{
private:
    Node<T> *root;

    int getHeight(Node<T> *p)
    {
        if (p->left && p->right) // all r not null
        {
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else
                return p->left->height + 1;
        }
        else
        {
            if (p->left && p->right == nullptr)
                return p->left->height + 1;
            else
            {
                if (p->left == nullptr && p->right)
                    return p->right->height + 1;
            }
        }
        return 0;
    }

    int BalancedFactor(Node<T> *p)
    {
        if (p->left && p->right)
        {
            return p->left->height - p->right->height;
        }
        else if (p->left && p->right == nullptr)
        {
            return p->left->height;
        }
        else if (p->left == nullptr && p->right)
        {
            return -p->right->height;
        }
    }

    Node<T> *LLrotation(Node<T> *root)
    {
        Node<T> *p;
        Node<T> *tp;
        p = root;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp;
    }

    Node<T> *RRrotation(Node<T> *n)
    {
        Node<T> *p;
        Node<T> *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp;
    }

    Node<T> *RLrotation(Node<T> *n)
    {
        Node<T> *p;
        Node<T> *tp;
        Node<T> *tp2;
        p = n;
        tp = p->right;
        tp2 = p->right->left;

        p->right = tp2->left;
        tp->left = tp2->right;
        tp2->left = p;
        tp2->right = tp;

        return tp2;
    }

    Node<T> *LRrotation(Node<T> *r)
    {
        Node<T> *p;
        Node<T> *tp;
        Node<T> *tp2;
        p = r;
        tp = p->left;
        tp2 = p->left->right;

        p->left = tp2->right;
        tp->right = tp2->left;
        tp2->right = p;
        tp2->left = tp;

        return tp2;
    }

    Node<T> *insert(Node<T> *r, T data)
    {

        if (r == nullptr)
        {
            Node<T> *p;
            p = new Node<T>(data);
            return p;
        }
        else
        {
            if (data < r->data)
                r->left = insert(r->left, data);
            else
                r->right = insert(r->right, data);
        }

        r->height = getHeight(r);

        if (BalancedFactor(r) == 2 && BalancedFactor(r->left) == 1)
        {
            r = LLrotation(r);
        }
        else if (BalancedFactor(r) == -2 && BalancedFactor(r->right) == -1)
        {
            r = RRrotation(r);
        }
        else if (BalancedFactor(r) == -2 && BalancedFactor(r->right) == 1)
        {
            r = RLrotation(r);
        }
        else if (BalancedFactor(r) == 2 && BalancedFactor(r->left) == -1)
        {
            r = LRrotation(r);
        }

        return r;
    }

    Node<T> * deleteNode(Node<T> *p, T data)
    {
        if (p->left == nullptr && p->right == nullptr)
        {
            if (p == this->root)
                this->root = nullptr;
            delete p;
            return nullptr;
        }

        Node<T> *t;
        Node<T> *q;
        if (p->data < data)
        {
            p->right = deleteNode(p->right, data);
        }
        else if (p->data > data)
        {
            p->left = deleteNode(p->left, data);
        }
        else
        {
            if (p->left != nullptr)
            {
                q = rightMost(p->left);
                p->data = q->data;
                p->left = deleteNode(p->left, q->data);
            }
            else
            {
                q = leftMost(p->right);
                p->data = q->data;
                p->right = deleteNode(p->right, q->data);
            }
        }

        if (BalancedFactor(p) == 2 && BalancedFactor(p->left) == 1)
        {
            p = LLrotation(p);
        }
        else if (BalancedFactor(p) == 2 && BalancedFactor(p->left) == -1)
        {
            p = LRrotation(p);
        }
        else if (BalancedFactor(p) == 2 && BalancedFactor(p->left) == 0)
        {
            p = LLrotation(p);
        }
        else if (BalancedFactor(p) == -2 && BalancedFactor(p->right) == -1)
        {
            p = RRrotation(p);
        }
        else if (BalancedFactor(p) == -2 && BalancedFactor(p->right) == 1)
        {
            p = RLrotation(p);
        }
        else if (BalancedFactor(p) == -2 && BalancedFactor(p->right) == 0)
        {
            p = LLrotation(p);
        }

        return p;
    }

    Node<T> *rightMost(Node<T> *p)
    {
        while (p->right != nullptr)
            p = p->right;
        return p;
    }

    Node<T> *leftMost(Node<T> *p)
    {
        while (p->left != nullptr)
            p = p->left;

        return p;
    }

    void eraseAll(Node<T> *r)
    {
        if (r == nullptr)
            return;

        eraseAll(r->left);
        eraseAll(r->right);

        delete r;
    }

    void PrintTree(Node<T> *r, int h)
    {
        if (r == nullptr)
        {
            for (int i = 0; i < h; ++i)
                std::cout << "     ";
            std::cout << "*    " << std::endl;
        }

        else
        {
            PrintTree(r->right, h + 1);
            for (int i = 0; i < h; ++i)
                std::cout << "     ";
            std::cout << r->data << std::endl;
            PrintTree(r->left, h + 1);
        }
    }

    void preOrder(Node<T> *r)
    {
        if (r == nullptr)
            return;
        std::cout << r->data << " ";
        preOrder(r->left);
        preOrder(r->right);
    }
    void inOrder(Node<T> *r)
    {
        if (r == nullptr)
            return;
        inOrder(r->left);
        std::cout << r->data << " ";
        inOrder(r->right);
    }
    void postOrder(Node<T> *r)
    {
        if (r == nullptr)
            return;
        postOrder(r->left);
        postOrder(r->right);
        std::cout << r->data << " ";
    }

    bool contain(Node<T> *r, T data)
    {
        if (r == nullptr)
            return false;
        if (data < r->data)
            return contain(r->left, data);
        else if (data > r->data)
            return contain(r->right, data);
        else
        {
            return true;
        }
    }

    bool isLeafSameHeight(Node<T>* r, int& ans)
    {
        if(r == nullptr) return 0;

        if(r->left && r->right)
        {
            if(r->left->height == r->right->height) 
            {
                r->height = r->left->height + 1;

            }
            else ans = 0;
        }
        else if(r->left == nullptr && r->right != nullptr)
        {
            r->height = r->right->height + 1;
        }
        else if(r->left != nullptr && r->right == nullptr)
        {
            r->height = r->left->height + 1;
        }
    }

public:
    AVL()
    {
        this->root = nullptr;
    }
    ~AVL()
    {
        eraseAll(this->root);
    }
    void insert(T data)
    {
        this->root = insert(this->root, data);
    }

    void erase(T data)
    {
        this->root = deleteNode(this->root, data);
    }

    // interface
    void PrintTree()
    {
        PrintTree(this->root, 0);
    }

    void preOrder()
    {
        preOrder(this->root);
    }

    void inOrder()
    {
        inOrder(this->root);
    }

    void postOrder()
    {
        postOrder(this->root);
    }
    bool contain(T data)
    {
        return contain(this->root, data);
    }

    int getHeight()
    {
        return getHeight(this->root);
    }

    bool isLeafSameHeight()
    {
        int ans = 1;

        isLeafSameHeight(root, ans);

        if(ans) return true;
        else return false;
    }
};