#include <algorithm>
#include <vector>

// default: increasing
// để sửa lại decresing ta chỉ cần sửa lại dấu của dòng 16, 17, 21

//co the dung bat ki kieu du lieu nao cung duoc mien la chung ta dinh nghia phep so sanh cho no 
template<typename T>
int partition(std::vector<T> &a, int l, int r)
{
    int randomIndex = std::rand() % (r - l + 1) + l;
    std::swap(a[r], a[randomIndex]);
    T pivot = a[r];
    int low = l;
    int high = r - 1;
    while (low < high)
    {
        while (low < high && a[low] <= pivot) low++;
        while (low < high && a[high] >= pivot) high--;
        std::swap(a[low], a[high]);
    }

    if (a[low] > a[r]) std::swap(a[low], a[r]);
    else low = r;

    return low;
}
template<typename T>
void sort(std::vector<T> &a, int l, int r)
{
    if (l >= r)
        return;

    int p = partition(a, l, r);
    sort(a, l, p - 1);
    sort(a, p + 1, r);
}