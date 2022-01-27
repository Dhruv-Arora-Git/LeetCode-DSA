// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/1723660/C%2B%2B-Binary-Search-Solution-or-Similar-to-book-allocation-problem

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool isValid(vector<int> &arr, int m, int k, int mx)
{
    vector<int> temp = arr;
    int bouqets = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        temp[i] -= mx;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        int flower = 0;
        while (i < temp.size() && temp[i] <= 0)
        {
            flower++;
            i++;
        }
        if (flower >= k)
        {
            bouqets += flower / k;
        }
    }
    if (bouqets < m)
        return false;

    return true;
}

int minDays(vector<int> &arr, int m, int k)
{
    if (m * k > arr.size())
        return -1;

    int min = INT_MAX, mx = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > mx)
            mx = arr[i];
    }

    int start = min, end = mx;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isValid(arr, m, k, mid) == true)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> bloomDay = {97, 83};
    int m = 2, k = 1;
    int ans = minDays(bloomDay, m, k);
    cout << ans << '\n';
    return 0;
}