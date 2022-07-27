#include <algorithm>

template <typename T>
void insertionSort(T[], int left, int right) 
{
    T v;
    int j;
    for(int i = left+1; i<=right; ++i)
    {
        v = a[i];
        for (j=i; j > left && v < a[j-1]; j--)
        {
            a[j] = a[j-1];
        }
        a[j] = v; 
    }
}