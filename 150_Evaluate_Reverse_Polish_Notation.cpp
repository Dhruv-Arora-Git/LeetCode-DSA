// https://leetcode.com/problems/evaluate-reverse-polish-notation/

// https://leetcode.com/problems/evaluate-reverse-polish-notation/discuss/1933829/C%2B%2B-Postfix-Evaluation-using-Stack-%3A)-Commented-Explanation

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isOperator(string c)
{
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

int evalRPN(vector<string> &tokens)
{
    stack<int> stk;

    for (const string &s : tokens)
    {
        // if its an operator, perform the operation
        if (isOperator(s))
        {
            // ex -> 2,4,/ => 4/2, thats why we take topmost element as second
            int second = stk.top();
            stk.pop();
            int first = stk.top();
            stk.pop();

            // string to char to use in switch
            char op = s[0];

            switch (op)
            {
            case '+':
                stk.push(first + second);
                break;
            case '-':
                stk.push(first - second);
                break;
            case '*':
                stk.push(first * second);
                break;
            case '/':
                stk.push(first / second);
                break;
            }
        }
        else // its a number, push it to stack
        {
            // convert the token to int and push it to stack
            stk.push(stoi(s));
        }
    }

    // the only element left in the stack is our answer
    return stk.top();
}

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens) << endl;

    return 0;
}