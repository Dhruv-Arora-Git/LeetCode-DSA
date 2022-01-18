// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

// https://leetcode.com/problems/find-smallest-letter-greater-than-target/discuss/1699556/simple-Binary-Search-or-C%2B%2B-or-O(log-n)

#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int start = 0, end = letters.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (letters[mid] <= target)
            start = mid + 1;

        else if (letters[mid] > target)
            end = mid - 1;
    }
    // because it wrap arounds
    return letters[start % letters.size()];
}

int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';

    cout << nextGreatestLetter(letters, target) << '\n';
    return 0;
}