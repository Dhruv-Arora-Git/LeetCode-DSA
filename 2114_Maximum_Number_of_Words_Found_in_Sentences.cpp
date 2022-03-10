// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/discuss/1836648/A-Simple-C%2B%2B-Solution-or-for-beginners

#include <iostream>
#include <vector>

using namespace std;

int mostWordsFound(vector<string> &sentences)
{
    int mx = -1;
    for (string &s : sentences)
    {
        int len = 1;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ')
                len++;
        }
        // cout << len << " ";
        mx = max(mx, len);
    }
    return mx;
}

int main()
{
    vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    cout << mostWordsFound(sentences) << '\n';

    return 0;
}