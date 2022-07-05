// https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/

// https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/discuss/2242193/C%2B%2B-O(1)-oror-Simple-Maths-oror-Easy-to-understand

#include <iostream>
#include <vector>

using namespace std;

// (n - 1) + n + (n + 1) => n + n + n (-1 +1) => 3n
vector<long long> sumOfThree(long long num)
{
    if (num % 3 != 0)
        return {};

    vector<long long> ans;

    long long n = num / 3;

    ans.push_back(n - 1);
    ans.push_back(n);
    ans.push_back(n + 1);

    return ans;
}

int main()
{
    int num = 33;
    vector<long long> ans = sumOfThree(num);

    for (const long long &a : ans)
        cout << a << " ";
    cout << "\n";

    return 0;
}