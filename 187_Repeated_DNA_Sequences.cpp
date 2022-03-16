// https://leetcode.com/problems/repeated-dna-sequences/

// https://leetcode.com/problems/repeated-dna-sequences/discuss/1855147/C%2B%2B-Explained-with-Comments-or-O(n)-time

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> findRepeatedDnaSequences(string &s)
{

    // we are using hashsets as we just want to check if it has frequency > 1
    // as we only want to check for frequency > 1, we can just check if it's already present or not
    // if it's already there, just add it in result set

    unordered_set<string> visited, result;

    int n = s.length();

    for (int i = 0; i < n - 9; ++i)
    {
        // taking the substring of length 10 (can say it's a window of length 10)
        string sub = s.substr(i, 10);

        // if our visited set already has it, it means a duplicate that is frequency of that substring is > 1, just add it in result set
        if (visited.find(sub) != visited.end())
            result.insert(sub);
        // else just insert in that set
        else
            visited.insert(sub);
    }

    // making vector as we have to return it in this function
    vector<string> ans_arr;

    for (const string &s : result)
        ans_arr.push_back(s);

    return ans_arr;
}

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ans = findRepeatedDnaSequences(s);

    for (const string &str : ans)
        cout << str << " ";

    cout << '\n';

    return 0;
}