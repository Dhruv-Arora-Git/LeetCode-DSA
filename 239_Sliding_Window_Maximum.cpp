// https://leetcode.com/problems/sliding-window-maximum/

// https://leetcode.com/problems/sliding-window-maximum/discuss/2548246/C%2B%2B-MaxHeap-and-Deque-Solutions-Explained

#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow1(vector<int> &arr, int k)
{

    if (k == 1)
        return arr;

    vector<int> ans;
    multiset<int> maxHeap;

    int n = arr.size();
    int j = 0;

    for (int i = 0; i < n; ++i)
    {
        if (maxHeap.size() < k)
        {
            maxHeap.insert(arr[i]);
        }

        if (maxHeap.size() == k)
        {
            ans.push_back(*maxHeap.rbegin());
            maxHeap.erase(maxHeap.find(arr[j++]));
        }
    }

    return ans;
}

vector<int> maxSlidingWindow2(vector<int> &arr, int k)
{

    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < arr.size(); ++i)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (i - k + 1 >= 0)
            ans.push_back(arr[dq.front()]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3; // output: 3, 3, 5, 5, 6, 7

    vector<int> ans = maxSlidingWindow1(arr, k);

    for (int &i : ans)
        cout << i << " ";
    cout << "\n";
    return 0;
}
