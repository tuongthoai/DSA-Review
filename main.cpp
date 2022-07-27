#include <iostream>
#include <vector>
#include "./Sorting/mergeSort.h"

using namespace std;

int main()
{
    vector<int> a = {1, 2, 5, 741231, 1234,5,345,34,12}, tmp(a);
    sort(a, tmp, 0, a.size() - 1);

    for(auto& x : a) cout << x << ' ' ;
    return 0;
}