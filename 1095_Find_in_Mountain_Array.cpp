// https://leetcode.com/problems/find-in-mountain-array/

// https://leetcode.com/problems/find-in-mountain-array/discuss/1702251/C%2B%2B-or-Find-Peak-or-Binary-Search-or-0-ms-faster-than-100

#include <iostream>
#include <vector>

using namespace std;
// used vector here, to run in local machine
// refer submission link (line no. 3) for MountainArray interface implementation
int peakIndex(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1])
            end = mid;
        else
            start = mid + 1;
    }

    return end;
}

int orderAgnosticBS(vector<int> &arr, int target, int start, int end)
{

    bool rev = arr[start] > arr[end];
    // cout << rev << endl;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int ele = arr[mid];
        if (ele == target)
            return mid;
        else if (ele < target)
        {
            if (rev)
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if (ele > target)
        {
            if (rev)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> mountainArr = {1, 2, 3, 4, 5, 3, 1};
    int target = 2;
    // cout << peakIndex(arr) << '\n';
    int peak = peakIndex(mountainArr);
    // cout << peak << endl;

    int ans = orderAgnosticBS(mountainArr, target, 0, peak);
    // cout << ans << endl;
    if (ans == -1)
        ans = orderAgnosticBS(mountainArr, target, peak + 1, mountainArr.size() - 1);

    cout << ans << '\n';
    return 0;
}