// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/discuss/1685141/C%2B%2B-easy-solution-or-with-comments-or-O(n)
#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{

    int n = candies.size();

    vector<bool> maxCandiesKids(n);

    // to store maximum number of candies a kid has
    int maxCandies = -1;
    for (int i : candies)
        maxCandies = max(maxCandies, i);

    for (int i = 0; i < n; i++)
    {
        // comparing candies of each kid + extra candies
        // if they are greater than or equal to max candies
        // then set true in our bool array
        if (candies[i] + extraCandies >= maxCandies)
            maxCandiesKids[i] = true;
    }
    // default value of boolean array is false
    // so, no need of else statement

    return maxCandiesKids;
}

int main()
{
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 1;

    vector<bool> kids = kidsWithCandies(candies, extraCandies);

    // {true,true,true,false,true}
    for (bool b : kids)
        cout << boolalpha << b << " ";

    cout << '\n';

    return 0;
}