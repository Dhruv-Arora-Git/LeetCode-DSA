#include <iostream>
#include <stack>
#include <vector>
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

int maximalRectangle(vector<vector<char>> &matrix)
{

    vector<int> histogram;

    int n = matrix.size(), m = matrix[0].size();

    // condensing 2D array to 1D array (to make it similar to Max Area Rectangle in Histogram)
    for (int i = 0; i < m; ++i)
    {
        histogram.push_back(matrix[0][i] - '0');
    }

    int max_area = largestRectangleArea(histogram);

    for (int i = 1; i < n; ++i)
    {

        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == '0')
                histogram[j] = 0;
            else
                ++histogram[j];
        }
        // finding area of each histogram, and comparing for the max
        max_area = max(max_area, largestRectangleArea(histogram));
    }

    return max_area;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };

    cout << maximalRectangle(matrix) << '\n';
    return 0;
}