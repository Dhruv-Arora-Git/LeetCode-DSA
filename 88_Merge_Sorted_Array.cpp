// https://leetcode.com/problems/merge-sorted-array/

// https://leetcode.com/problems/merge-sorted-array/discuss/1650612/2-Pointer-Solution-oror-C%2B%2B-oror-O(m-%2B-n)-runtime-oror-Constant-Space-O(1)

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

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (m == 0)
    {
        nums1 = nums2;
        return;
    }

    if (n == 0)
    {
        return;
    }

    int first = m - 1, zero = m + n - 1;
    int second = n - 1;

    while (first >= 0 && second >= 0)
    {
        if (nums1[first] <= nums2[second])
            nums1[zero--] = nums2[second--];
        else
            nums1[zero--] = nums1[first--];
    }

    while (second >= 0)
    {
        nums1[zero--] = nums2[second--];
    }
    // return nums1;
}
int main()
{
    vector<int> a = {4, 0, 0, 0, 0, 0};
    int size1 = 1;
    vector<int> b = {1, 2, 3, 5, 6};
    int size2 = 5;

    merge2(a, size1, b, size2);

    for (int i : a)
        cout
            << i << " ";
    cout << '\n';

    return 0;
}