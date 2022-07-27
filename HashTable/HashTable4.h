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
    const int primes[100] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};

    int tSize, counter, P;

    std::vector<int> h;

    int hash1(int x) {return x % tSize;}

    int hash2(int x) {return P - (x % P); }


    HashTable()
    {
        tSize = 1003;
        counter = 0;

        P = primes[99];


        for(int i = 0; i < tSize; ++i)
        {
            h.push_back(-1);
        }
    }

    void insert(int k)
    {
        if(counter == tSize) return;

        int probe = hash1(k), offset = hash2(k);
        while(h[probe] != -1)
        {
            probe = (probe+offset) % tSize;
        }

        h[probe] = k;
        counter++;
    }

    int find(int value){
		int probe = hash1(value), offset = hash2(value), initialPos = probe;
		bool firstItr = true;

		while(1){
			if(h[probe] == -1)				 // Stop search if -1 is encountered.
				break;
			else if(h[probe] == value)		 // Stop search after finding the element.
				return value;
			else if(probe == initialPos && !firstItr) // Stop search if one complete traversal of hash table is completed.
				return false;
			else
				probe = ((probe + offset) % tSize); // if none of the above cases occur then update the index and check at it.

			firstItr = false;
		}
		return INT_MIN;
	}


};