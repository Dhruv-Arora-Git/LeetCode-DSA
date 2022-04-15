// https://leetcode.com/problems/min-stack/

// https://leetcode.com/problems/min-stack/discuss/1948714/C%2B%2B-Using-an-Extra-Stack-or-Super-Simple-()

#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> stk;
    stack<int> minStk;

public:
    void push(int val)
    {
        stk.push(val);

        if (minStk.empty() or val <= minStk.top())
            minStk.push(val);
    }

    void pop()
    {
        if (stk.empty()) // although, it's guarnteed that stack will not be empty, but still it's a good practice to check it before pop(), top() and getMin()
            return;

        if (stk.top() == minStk.top())
            minStk.pop();

        stk.pop();
    }

    int top()
    {
        if (stk.empty())
            return -1;

        return stk.top();
    }

    int getMin()
    {
        if (minStk.empty())
            return -1;

        return minStk.top();
    }
};

int main()
{

    return 0;
}