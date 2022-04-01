// https://leetcode.com/problems/median-of-two-sorted-arrays/

// https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/1902554/Simple-Merge-2-Arrays-O(m-%2B-n)-C%2B%2B-Solution-%3A)

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> merged_arr;

    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();

    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
        {
            merged_arr.push_back(nums1[i]);
            i++;
        }
        else
        {
            merged_arr.push_back(nums2[j]);
            j++;
        }
    }

    while (i < n)
    {
        merged_arr.push_back(nums1[i]);
        i++;
    }

    while (j < m)
    {
        merged_arr.push_back(nums2[j]);
        j++;
    }

    int sz = merged_arr.size();

    // for (int i = 0; i < sz; ++i)
    //     cout << merged_arr[i] << " ";

    if (sz & 1)
    {
        // odd
        return merged_arr[sz / 2];
    }

    return (merged_arr[(sz / 2) - 1] + merged_arr[sz / 2]) / 2.0;
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    cout << findMedianSortedArrays(nums1, nums2) << "\n";
    return 0;
}