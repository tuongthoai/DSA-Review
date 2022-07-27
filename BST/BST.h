#include <vector>
#include <algorithm>

template <class Key, class Value>
class BST
{
private:
    struct Node
    {
        Key key;
        Value val;
        Node *left, *right;

        Node(Key _key, Value _val)
        {
            this->key = _key;
            this->val = _val;

            left = nullptr;
            right = nullptr;
        }
    };

    typedef Node *link;
    link root;

public:
    BST() { root = nullptr; }

    void PrintTree(link r, int h)
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
            std::cout << r->key << std::endl;
            PrintTree(r->left, h + 1);
        }
    }
    // interface
    void PrintTree()
    {
        PrintTree(root, 0);
    }

    bool find(Key key)
    {
        if (root == nullptr)
            return 0;

        link cur = root;
        for (; cur != nullptr;)
        {
            if (key == cur->key)
                return 1;
            if (key < cur->key)
                cur = cur->left;
            else
                cur = cur->right;
        }

        return 0;
    }

    void Insert(link &r, Key key, Value value) // implement
    {
        if (r == nullptr) // base case
        {
            r = new Node(key, value);
        }

        // recursive case
        else
        {
            if (r->key == key)
                return;
            if (r->key > key)
                Insert(r->left, key, value);
            if (r->key < key)
                Insert(r->right, key, value);
        }
    }

    void Insert(Key key, Value value)
    {
        Insert(root, key, value);
    }

    void Update(Key key, Value val)
    {
        if (root == nullptr)
            return;

        link cur = root;
        for (; cur != nullptr;)
        {
            if (key == cur->key)
            {
                cur->val = val;
            }
            if (key < cur->key)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    link minValLink(link r)
    {
        link cur = r;
        while (cur && cur->left != nullptr)
            cur = cur->left;

        return cur;
    }

    link deleteLink(link root, Key key)//implementation
    {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteLink(root->left, key);

        else if (key > root->key)
            root->right = deleteLink(root->right, key);
        else
        {
            if (root->left == nullptr and root->right == nullptr)
                return nullptr;
            else if (root->left == nullptr)
            {
                link temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                link temp = root->left;
                delete root;
                return temp;
            }

            link temp = minValLink(root->right);
            root->key = temp->key;
            root->right = deleteLink(root->right, temp->key);
        }
        return root;
    }

    void Erase(Key key)
    {
        root = deleteLink(root, key);
    }

    void deleteAll(link root)
    {
        if(root != nullptr)
        {
            deleteAll(root->left);
            deleteAll(root->right);
            delete root;
        }
    }

    ~BST()
    {
        deleteAll(root);
    }

    void getAllLinkValue(link r, std::vector<Value>& a)
    {
        if(r == nullptr) return;

        a.push_back(r->val);
        getAllLinkValue(r->left, a);
        getAllLinkValue(r->right, a);
    }
};
