#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> numPad(string processed, string original)
{
    if (original.empty())
    {
        vector<string> v;
        v.push_back(processed);
        return v;
    }

    int num = original[0] - '0'; // char to int
    vector<string> ans;
    int start, end;

    // consider a = 0, b = 1, c = 2, .... y = 24, z = 25
    // according to key, assign that number
    // and make recursive calls

    if (num == 7)
        start = 15, end = 19; // p,q,r,s
    else if (num == 8)
        start = 19, end = 22; // t,u,v
    else if (num == 9)
        start = 22, end = 26; // w,x,y,z
    else
        start = (num - 2) * 3, end = (num - 1) * 3;
    // ex - 5
    // start = (5-2)*3 => 9 , end = (5-1)*3 => 12
    // 9 = j, 10 = k, 11 = l

    // loop from start till *end - 1*
    for (int i = start; i < end; i++)
    {
        char ch = char('a' + i);
        string passIt = "";
        passIt.push_back(ch);

        // getting answers from below recursion calls
        vector<string> ansFromCalls = numPad(processed + passIt, original.substr(1));
        // inserting answers into our local vector (ans)
        ans.insert(ans.end(), ansFromCalls.begin(), ansFromCalls.end());
    }
    // return that ans, it wil contain every possible combination
    return ans;
}

int main()
{
    string digits = "23";
    // if string is empty, just return an empty vector

    // if (digits.empty())
    // {
    //     vector<string> ans;
    //     return ans;
    // }

    // else call that recursive function
    vector<string> ans = numPad("", digits);

    for (const string &s : ans)
    {
        cout << s << '\n';
    }

    return 0;
}