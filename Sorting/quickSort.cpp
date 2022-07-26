#include <algorithm>
#include <vector>

template<typename T>
bool T_smaller(const T& a, const T& b)
{
    //do something here
    return a < b;
}

template<typename T>
bool T_larger(const T& a, const T& b)
{
    //do something here
    return a > b;
}

template<typename T>
int partition(std::vector<T>& a, int l, int r)
{
    int randomIndex = std::rand() % (r - l + 1) + l;

    // int tmp = a[r];
    // a[r] = a[randomIndex];
    // a[randomIndex] = tmp;

    std::swap(a[r], a[randomIndex]);

    T pivot = a[r];

    int low = l;
    int high = r - 1;
    while (low < high)
    {
        while (low < high && T_smaller(a[low], pivot))
            low++;
        while (low < high && T_larger(a[high], pivot))
            high--;
        std::swap(a[low], a[high]);
    }

    if (T_larger(a[low], a[r]))
    {
        std::swap(a[low], a[r]);
    }
    else
        low = r;

    return low;
}


template<typename T>
void sort(std::vector<T>& a, int l, int r)
{
    if (l >= r)
        return;

    int p = partition<T>(a, l, r);
    sort(a, l, p - 1);
    sort(a, p + 1, r);
}