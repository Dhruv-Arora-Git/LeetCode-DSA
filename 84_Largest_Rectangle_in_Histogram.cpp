// https://leetcode.com/problems/largest-rectangle-in-histogram/

// https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/1942840/Next-Smaller-to-Left-%2B-Next-Smaller-to-Right-Solution-(-)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> nearestSmallerToLeft(const vector<int> &arr)
{
    vector<int> left;

    stack<pair<int, int>> stk;

    for (int i = 0; i < arr.size(); ++i)
    {
        if (stk.size() == 0)
            left.push_back(-1);

        else if (stk.top().first < arr[i])
            left.push_back(stk.top().second);

        else if (stk.top().first >= arr[i])
        {

            while (stk.size() > 0 && stk.top().first >= arr[i])
                stk.pop();

            if (stk.size() == 0)
                left.push_back(-1);
            else
                left.push_back(stk.top().second);
        }

        stk.push({arr[i], i});
    }

    return left;
}

vector<int> nearestSmallerToRight(const vector<int> &arr)
{
    vector<int> right;

    stack<pair<int, int>> stk;

    for (int i = arr.size() - 1; i >= 0; --i)
    {
        if (stk.size() == 0)
            right.push_back(arr.size());

        else if (stk.top().first < arr[i])
            right.push_back(stk.top().second);

        else if (stk.top().first >= arr[i])
        {

            while (stk.size() > 0 && stk.top().first >= arr[i])
                stk.pop();

            if (stk.size() == 0)
                right.push_back(arr.size());
            else
                right.push_back(stk.top().second);
        }

        stk.push({arr[i], i});
    }

    reverse(right.begin(), right.end());

    return right;
}

int largestRectangleArea(vector<int> &heights)
{

    // how much each element (height) can expand it's width to left
    vector<int> left = nearestSmallerToLeft(heights);

    // how much each element (height) can expand it's width to right
    vector<int> right = nearestSmallerToRight(heights);

    // width of all elements (right - left - 1)
    vector<int> width;

    for (int i = 0; i < left.size(); ++i)
    {
        width.push_back(right[i] - left[i] - 1);
    }

    int mx_area = -1;
    // area = length * width
    for (int i = 0; i < width.size(); ++i)
    {
        int area = width[i] * heights[i];

        mx_area = max(mx_area, area);
    }

    return mx_area;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << largestRectangleArea(heights) << '\n';

    return 0;
}