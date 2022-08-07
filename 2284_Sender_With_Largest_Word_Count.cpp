// https://leetcode.com/problems/sender-with-largest-word-count/

// https://leetcode.com/problems/sender-with-largest-word-count/discuss/2393337/BruteForce-to-Optimal-Solution-or-Explained-C%2B%2B

#include <iostream>
#include <climits>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// Brute Force
string largestWordCount(vector<string> &messages, vector<string> &senders)
{
    int n = senders.size();

    unordered_map<string, int> freq;
    int mx = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;

        stringstream ss(messages[i]);
        string word;

        while (ss >> word)
            ++cnt;

        freq[senders[i]] += cnt;
        mx = max(mx, freq[senders[i]]);
    }

    set<string> st;

    for (auto &it : freq)
        if (it.second == mx)
            st.insert(it.first);

    return *st.rbegin();
}

// optimal solution
string largestWordCount2(vector<string> &messages, vector<string> &senders)
{
    int n = senders.size();
    string maxString = "";
    int maxMsgs = 0;

    unordered_map<string, int> count;

    for (int i = 0; i < n; ++i)
    {
        int words = 1; // total spaces + 1
        string msg = messages[i];
        string sender = senders[i];

        for (const char &c : msg)
            if (c == ' ')
                ++words;

        count[sender] += words;

        if ((count[sender] > maxMsgs) || (count[sender] == maxMsgs && sender > maxString))
        {
            maxString = sender;
            maxMsgs = count[sender];
        }
    }

    return maxString;
}

int main()
{
    vector<string> messages = {"Hello userTwooo", "Hi userThree", "Wonderful day Alice", "Nice day userThree"};
    vector<string> senders = {"Alice", "userTwo", "userThree", "Alice"};

    cout << largestWordCount(messages, senders) << "\n";
    cout << largestWordCount2(messages, senders) << "\n";

    return 0;
}