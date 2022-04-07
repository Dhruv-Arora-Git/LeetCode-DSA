// https://leetcode.com/problems/last-stone-weight/

// https://leetcode.com/problems/last-stone-weight/discuss/1923115/C%2B%2B-max-heap-or-priority-queue-or-Faster-than-100-(-)

#include <bits/stdc++.h>

using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    int n = stones.size();

    if (n == 1)
        return stones[0];

    priority_queue<int> max_heap;

    // insert all the stones into the max heap
    for (int i = 0; i < n; ++i)
    {
        max_heap.push(stones[i]);
    }

    // while there is only 1 element left in the heap
    while (max_heap.size() != 1)
    {
        // max of all the stones
        int first = max_heap.top();
        max_heap.pop(); // remove the max

        // second max of all the stones
        int sec = max_heap.top();
        max_heap.pop(); // remove the second max

        // push the difference of the two max into the max heap
        max_heap.push(first - sec);
    }

    // return the last element in the heap
    return max_heap.top();
}

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    cout << lastStoneWeight(stones) << "\n";
    return 0;
}