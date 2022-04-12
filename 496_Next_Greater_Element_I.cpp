// https://leetcode.com/problems/next-greater-element-i/

// https://leetcode.com/problems/next-greater-element-i/discuss/1939816/C%2B%2B-Stack-%2B-unordered_map-or-easy-to-read-and-understand

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> stk;

    unordered_map<int, int> mapping;

    for (int i = nums2.size() - 1; i >= 0; --i)
    {
        if (stk.size() == 0)
            mapping.insert({nums2[i], -1});

        else if (stk.top() > nums2[i])
            mapping.insert({nums2[i], stk.top()});

        else if (stk.top() <= nums2[i])
        {

            while (stk.size() > 0 && stk.top() <= nums2[i])
                stk.pop();

            if (stk.size() == 0)
                mapping.insert({nums2[i], -1});
            else
                mapping.insert({nums2[i], stk.top()});
        }

        stk.push(nums2[i]);
    }

    vector<int> ans;

    for (int i = 0; i < nums1.size(); ++i)
        ans.push_back(mapping[nums1[i]]);

    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";

    cout << '\n';

    return 0;
}