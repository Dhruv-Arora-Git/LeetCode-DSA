// https://leetcode.com/problems/duplicate-zeros/

// https://leetcode.com/problems/duplicate-zeros/discuss/1650581/C%2B%2B-O(n)-time-O(n)-space-Easy-Readable-Solution

#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n);
    int index = 0;

    for (int i = 0; index < temp.size(); i++)
    {
        if (arr[i] == 0 && (index + 1) < n)
        {
            temp[index++] = 0;
            temp[index++] = 0;
        }
        else
        {
            temp[index++] = arr[i];
        }
    }
    arr = temp;
}

int main()
{

    return 0;
}