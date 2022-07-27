#include <vector>

template<typename T>
void merge(std::vector<T> &a, std::vector<T> &aux, int l, int m, int r)
{
    int i, j, k;
    for (k = l; k <= r; k++)
        aux[k] = a[k];
    i = l;
    j = m + 1;
    k = l;
    while (i <= m && j <= r)
        if (aux[i] <= aux[j])
            a[k++] = aux[i++];
        else
            a[k++] = aux[j++];
    while (i <= m)
        a[k++] = aux[i++];
    while (j <= r)
        a[k++] = aux[j++];
}

template<typename T>
void sort(std::vector<T> &data, std::vector<T> &tmp, int l, int r)
{
    if (l >= r) return;
    int m = l + (r - l) / 2;
    sort(data, tmp, l, m);
    sort(data, tmp, m + 1, r);
    merge(data, tmp, l, m, r);
}