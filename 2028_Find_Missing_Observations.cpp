// https://leetcode.com/problems/find-missing-observations/description/

// https://leetcode.com/problems/find-missing-observations/solutions/2891978/c-intuition-explained-simple-and-easy-code/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    int sum = accumulate(rolls.begin(), rolls.end(), 0);
    int toFindSum = (mean * (n + rolls.size())) - sum;

    if (toFindSum > 6 * n || toFindSum < n)
        return {};

    int guess = toFindSum / n;
    vector<int> missing(n, guess);
    int extra = toFindSum % n;

    for (int i = 0; i < extra; ++i)
        missing[i] += 1;

    return missing;
}

int main()
{
    vector<int> rolls = {3, 2, 4, 3};
    int mean = 4, n = 2;

    vector<int> missing = missingRolls(rolls, mean, n);
    for (int &i : missing)
        cout << i << " ";

    cout << "\n";
    return 0;
}