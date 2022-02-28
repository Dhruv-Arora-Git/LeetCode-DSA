// https://leetcode.com/problems/kth-largest-element-in-an-array/

// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/1807073/2-Simple-approaches-or-for-beginners-or-C%2B%2B-solution-with-time-complexities

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// T.C. = O(n log(k))
// S.C. = O(k)
int findKthLargest(vector<int> &nums, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);

        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

// T.C. = O(n logn)
// S.C. = O(1)
int findKthLargest2(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end(), greater<int>());

    return nums[k - 1];
}
int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    cout << findKthLargest(nums, k) << '\n';
    return 0;
}