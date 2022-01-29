// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/1726672/C%2B%2B-or-Binary-Search-or-Simple-Solution-%3A)

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &weights, int days, int mx)
{
    int sum = 0;
    int req_days = 1;
    for (int i = 0; i < weights.size(); i++)
    {
        sum += weights[i];
        if (sum > mx)
        {
            req_days++;
            sum = weights[i];
        }
        if (req_days > days)
            return false;
    }

    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{

    int mx = -1, sum = 0;

    for (int i = 0; i < weights.size(); i++)
    {
        if (weights[i] > mx)
            mx = weights[i];
        sum += weights[i];
    }

    if (weights.size() == days)
        return mx;

    int start = mx, end = sum;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(weights, days, mid))
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
    vector<int> weights = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    int days = 4;
    cout << shipWithinDays(weights, days) << '\n';
    return 0;
}