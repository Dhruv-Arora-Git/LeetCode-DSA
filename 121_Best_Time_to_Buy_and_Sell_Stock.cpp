// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/1782804/C%2B%2B-2-Pointer-Approach-or-Simple-and-Easy-or-O(n)

#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    int buy = 0, sell = 1;
    int max_profit = 0;

    while (sell < n && buy < n)
    {
        if (prices[buy] >= prices[sell])
        {
            buy = sell;
            sell++;
        }
        else if (prices[buy] < prices[sell])
        {
            max_profit = max(max_profit, prices[sell] - prices[buy]);
            sell++;
        }
    }

    return max_profit;
}

int main()
{
    vector<int> prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0, 9};

    int ans = maxProfit(prices);

    cout << ans << '\n';
    return 0;
}