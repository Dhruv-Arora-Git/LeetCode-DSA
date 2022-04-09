// https://leetcode.com/problems/top-k-frequent-elements/

// https://leetcode.com/problems/top-k-frequent-elements/discuss/1929673/C%2B%2B-Simple-HashMap-and-MultiMap-solution-(-)

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    // hashmap to store frequency of each element
    unordered_map<int, int> freq_map;

    for (int i = 0; i < nums.size(); ++i)
    {
        freq_map[nums[i]]++;
    }

    multimap<int, int> sorted_map;

    for (auto &it : freq_map)
    {
        //                  freq      value
        sorted_map.insert({it.second, it.first});
    }

    vector<int> arr;

    // as we want max frequency, we will iterate from the back (in reverse order)
    // that's why rbegin()
    auto it = sorted_map.rbegin();
    // we need k elements, so while k--
    while (k--)
    {
        //            it->second is value, it->first is freq
        arr.push_back(it->second);
        it++;
    }

    return arr;
}

int main()
{
    vector<int> nums = {4, 4, 4, 4, 5, 5, 7, 7, 7, 0, 1};
    int k = 2;

    vector<int> res = topKFrequent(nums, k);

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }

    return 0;
}