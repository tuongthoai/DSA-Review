#include <vector>

const int P = 1e6 + 3;

class HashTable {

public:

    std::vector< std::vector<int> > h;

    HashTable()
    {
        h.resize(P);
    }

    void insert(int key) {
        int hkey = getHash(key);
        for (auto p : h[hkey]) {
            if (p == key) {
                // key da ton tai trong Hash table, ta bo qua
                return;
            }
        }
        // Them (key, value) vao hash table
        h[hkey].emplace_back(key);
    }

    int find(int key) {
        int hkey = getHash(key);
        for(auto p : h[hkey]) {
            if (p == key) {
                // ton tai key trong Hash table, return value
                return p;
            }
        }
        // Khong tim thay
        return -2147483648;
    }

    int getHash(int key) {
        // Cho 1 key, tra lai Hash value la key % P
        return key % P;
    }
};