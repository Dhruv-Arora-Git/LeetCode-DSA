// https://leetcode.com/problems/unique-email-addresses/

// https://leetcode.com/problems/unique-email-addresses/discuss/1775689/C%2B%2B-basic-solution-or-Hash-Map

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
int numUniqueEmails(vector<string> &emails)
{
    unordered_map<string, int> cnt;

    for (int i = 0; i < emails.size(); i++)
    {

        string temp = "";
        string now = emails[i];

        for (int j = 0; now[j] != '@'; j++)
        {

            if (now[j] == '+')
                break;

            if (now[j] == '.')
                continue;

            temp.push_back(now[j]);
        }

        int index = now.find('@');

        while (index < now.size())
        {
            temp.push_back(now[index++]);
        }

        cnt[temp]++;
    }
    return cnt.size();
}

int main()
{
    vector<string> emails = {

        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"

    };
    cout << numUniqueEmails(emails) << '\n';
    return 0;
}