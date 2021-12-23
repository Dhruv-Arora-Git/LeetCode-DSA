// 88. Merge Sorted Array
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = n + m - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] < nums2[j])
            nums1[k--] = nums2[j--];
        else
            nums1[k--] = nums1[i--];
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

int main()
{
    vector<int> a = {4, 0, 0, 0, 0, 0};
    int size1 = 1;
    vector<int> b = {1, 2, 3, 5, 6};
    int size2 = 5;

    merge(a, size1, b, size2);

    cout << '\n';
    for (int i : a)
        cout
            << i << " ";
    cout << '\n';

    return 0;
}