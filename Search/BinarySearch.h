#include <algorithm>

template <typename T>
int BinarySearch(T a[], int left, int right, T key)
{
    if (right >= left)
    {
        int mid = (left + right)/2;

        if (a[mid] == key) return i;

        if (a[mid] > key) return BinarySearch(a,left,mid-1,key);
        else return BinarySearch(a,mid+1,right,key);
    }
}