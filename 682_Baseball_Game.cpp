// https://leetcode.com/problems/baseball-game/

// https://leetcode.com/problems/baseball-game/discuss/1933141/C%2B%2B-Stack-solution-explained-with-comments-)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int calPoints(const vector<string> &ops)
{
    stack<int> stk;

    for (const string &s : ops)
    {

        if (s == "C")
        {
            // remove the last record
            stk.pop();
        }
        else if (s == "D")
        {
            // double the last record
            int temp = stk.top(); // can use directly stk.push(2 * stk.top())
            stk.push(2 * temp);
        }
        else if (s == "+")
        {
            // add the last two records

            // take out last record
            int top1 = stk.top();
            stk.pop();

            int top2 = stk.top();
            // push back last record first, to maintain the order
            stk.push(top1);
            stk.push(top1 + top2); // push the sum of last two records
        }
        else
        {
            // convert the record to int and push it to stack
            int temp = stoi(s);
            stk.push(temp);
        }
    }

    int sum = 0;

    // add all the elements of stack
    while (!stk.empty())
    {
        sum += stk.top();
        stk.pop();
    }

    return sum;
}

int main()
{
    vector<string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};

    // cout << "Points are:\n";
    cout << calPoints(ops) << "\n";

    return 0;
}