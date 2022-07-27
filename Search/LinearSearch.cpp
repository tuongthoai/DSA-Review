#include <algorithm>

template <typename T>
int LinearSearch(T a[], int n, T key)
{
    for (int i=0; i<n; ++i)
    {
        if (a[i] == key) return i;
    }
    return -1;
}