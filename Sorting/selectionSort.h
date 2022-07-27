#include <algorithm>

template <typename T>
void selectionSort(T[], int left, int right)
{
    for (int i=left, i<right; ++i)
    {
        int min = i;
        for (int j=i+i; j<=right; ++j)
        {
            if (a[j] < a[min]) min = j;
        }
        std::swap(a[i],a[min]);
    }
}