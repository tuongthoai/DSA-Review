#include <vector>

#define INT_MIN -2147483648

struct Item
{
    int flag = 0;
    int key;
    int val;
};

struct HashTable
{
    std::vector<Item> h;
    int sz = (1 << 10);

    HashTable()
    {
        h.resize(sz);
    }

    int getHash(int key, int x)
    {
        return ((long long) key + ((long long)x * x + x)/2 )%sz;
    }

    void insert(int Key)
    {
        int hh = getHash(Key, 0);

        if(h[hh].flag == 0)
        {
            h[hh].key = h[hh].val = Key;
        }
        else
        {
            int newH = hh;
            int cnt = 0;
            while(h[newH].flag == 1 && cnt++ < sz)
            {
                newH = getHash(Key, cnt);
            }

            if(h[newH].flag == 1) return;

            h[newH].key = Key;
            h[newH].val = Key;
            h[newH].flag = 1;
        }
    }

    int find(int Key)
    {
        int hh = getHash(Key, 0);

        if(h[hh].flag == 0)
        {
            h[hh].key = h[hh].val = Key;
        }
        else
        {
            int newH = hh;
            int cnt = 0;
            while(h[newH].flag == 0 && cnt++ < sz)
            {
                newH = getHash(Key, cnt);
            }

            if(h[newH].flag == 0) return INT_MIN;

            return h[newH].key;
        }
    }
};