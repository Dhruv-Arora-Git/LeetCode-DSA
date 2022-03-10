// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/discuss/1836707/C%2B%2B-Solution-Explained-with-Comments-for-Beginners

#include <iostream>
#include <vector>

using namespace std;

bool canBeEqual(vector<int> &target, vector<int> &arr)
{
    // making an array to store count of each int present in target and arr vector
    int cnt[1001] = {0};

    // increasing the count of each int in target
    for (int &i : target)
    {
        cnt[i]++;
    }
    // now, decreasing the count of each int in arr
    for (int &i : arr)
    {
        cnt[i]--;
    }
    // ex -> target = {1,2,4}, arr = {2,4,1}
    // cnt[] after first for loop = {1,1,0,1}
    //  1,2,3,4

    // cnt[] after second for loop = {0,0,0,0}
    //  1,2,3,4

    // this loop will check if there is any element in cnt[] which is not 0
    // means the element which is not present in both he arrays, return false
    for (int i = 1; i < 1001; ++i)
        if (cnt[i] != 0)
            return false;

    // after coming out of loop, everything should be 0 in cnt[]
    // means, both vectors has same elements, return true
    return true;
}

int main()
{
    vector<int> target = {1, 2, 3, 4};
    vector<int> arr = {2, 4, 1, 3};

    cout << canBeEqual(target, arr) << '\n';

    return 0;
}