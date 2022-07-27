#define DEFAULT_TABLE_SIZE 127

template <typename K, typename V>
class Entry
{
public:
    K key;
    V value;

    Entry(K key, V val)
    {
        this->key = key;
        this->value = val;
    }
};

template <typename K, typename V>
class HashTable
{
private:
    typedef Entry<K, V> Ent;
    typedef unsigned int uint;

    const uint primes[9] = {127, 257, 521, 1051, 2153, 4327, 8669, 17351, 34739};

    float threshold;
    uint maxSize, tableSize, size, p_primes;
    Ent **T;

    void resize()
    {
        uint oldTableSize = tableSize;

        if (p_primes < 9)
        {
            tableSize = primes[p_primes++];        // ensure the size of the table is a prime number
            maxSize = (uint)threshold * tableSize; // maxsize to ensure the threshold

            Ent **oldTable = T;
            T = new Ent *[tableSize];

            for (int i = 0; i < tableSize; ++i)
                T[i] = nullptr; // init nullptr for table

            size = 0;

            for (int i = 0; i < oldTableSize; ++i)
            {
                if (oldTable[i] != nullptr)
                {
                    int h = 0;
                    uint slot = compute_hash(oldTable[i]->key);
                    for (slot = (slot + h * (h++)) % maxSize; oldTable[slot] != nullptr; slot = (slot + h * (h++)) % maxSize)
                    {
                        Ent *cur = oldTable[slot];
                        delete oldTable[slot];

                        insert(cur->key, cur->value);
                    }
                }
            }

            delete[] oldTable;
        }
    }

    unsigned int compute_hash(std::string const &s)
    {
        const int p = 257;
        const int m = tableSize;
        unsigned int hash_value = 0;
        long long p_pow = 1;
        for (char c : s)
        {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }

public:
    HashTable()
    {
        threshold = 0.5f;
        maxSize = threshold * DEFAULT_TABLE_SIZE;
        tableSize = DEFAULT_TABLE_SIZE;

        size = 0;

        T = new Ent *[tableSize];

        for (int i = 0; i < tableSize; ++i)
            T[i] = nullptr;
    }

    void insert(const K &key, const V val)
    {
        unsigned int slot = compute_hash(key);
        unsigned int nextSlot = slot;
        unsigned int attempt = 1;
        do
        {
            if (T[nextSlot] == nullptr)
            {
                T[nextSlot] = new Entry<K, V>(key, val);
                size++;
                return;
            }
            else
            {
                if (T[nextSlot]->key == key)
                    T[nextSlot]->value = val;
                return;
            }

            nextSlot = (nextSlot + attempt * (attempt + 1)) % tableSize;
            ++attempt;
        } while (slot != nextSlot);

        if (size > maxSize)
            this->resize();
    }

    Entry<K, V> *find(const K &key)
    {
        unsigned int slot = compute_hash(key), h = 1;
        while (T[slot] != nullptr)
        {
            if (T[slot]->key == key)
                return T[slot];
            slot = (slot + h * (h)) % tableSize;
            ++h;
        }
        return nullptr;
    }

    void erase(const K &key)
    {
        if (find(key) == nullptr)
            return;

        unsigned int slot = compute_hash(key);
        int h = 1;
        while (key != T[slot]->key)
            slot = (slot + h * h++) % tableSize;

        delete T[slot];
        T[slot] = nullptr;

        for (slot = (slot + h * (h++)) % tableSize ; T[slot] != nullptr; slot = (slot + h * (h++)) % tableSize)
        {
            Entry<K, V> *cur = T[slot];
            delete T[slot];

            --size;

            insert(cur->key, cur->value);
        }

        --size;
    }

    ~HashTable()
    {
        for(int i = 0; i < tableSize; ++i)
        {
            if(T[i] != nullptr) 
            {
                delete T[i];
            }
        }

        delete[] T;
    }
};
