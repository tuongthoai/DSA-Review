#include <vector>
#include <iostream>
struct HashTable
{
    const int P = 1e6 + 3;
    std::vector< std::pair<int,int> > h;
    int size = 0;

    HashTable()
    {
        h.resize(P, {0, 0});
    }

    int getHash(int key)
    {
        return key % P;
    }

    void insert(int key)
    {
        int addressing = getHash(key);
        int cnt = 0;
        while(h[addressing].first == 1 && cnt < P) 
        {
            if(cnt++ > P) return;

            addressing++;
            addressing %= P;
        }

        h[addressing].first = 1;
        h[addressing].second = key;
    }

    int find(int key)
    {
        int address = getHash(key);
        int counter = 0;
        while (h[address].first == 1) { 
            if (counter++ > this->P) 
                return -2147483648;

            if(h[address].second == key) return key;
            address++;
            address = address % P;
        }
        return -2147483648;
    }
};