#include <algorithm>

template <typename T>
int SenLinearSearch(T a[], int n, T key)
{
    T last = a[n-1];
    a[n-1] = key;

    int i = 0;
    while (arr[i] != key)
        i++;

    arr[n - 1] = last;
 
    if ((i < n - 1) || (arr[n - 1] == key))
        return i;
    else
        return -1;
}