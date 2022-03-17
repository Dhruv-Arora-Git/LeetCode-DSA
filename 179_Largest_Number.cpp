#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool my_cmp(const string &a, const string &b)
{
    return (a + b > b + a);
}

string largestNumber(vector<int> &nums)
{

    int count_0 = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 0)
            ++count_0;
    }

    if (count_0 == nums.size())
        return "0";

    vector<string> temp;

    for (int num : nums)
    {
        temp.push_back(to_string(num));
    }

    sort(temp.begin(), temp.end(), my_cmp);

    string s = "";

    for (const string &str : temp)
        s.append(str);

    return s;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << '\n';
    return 0;
}