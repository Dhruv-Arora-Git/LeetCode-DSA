// https://leetcode.com/problems/find-the-town-judge/

// https://leetcode.com/problems/find-the-town-judge/discuss/2066813/O(n)-Solution-or-using-Array-or-Explained!-C%2B%2B

#include <iostream>
#include <vector>

using namespace std;

/*

🔹 Condition to be a Judge : if a person has trust of all people and he trusts no one
So, we consider, in a Graph
outdegree : giving trust to someone
indegree : having trust of someone

🔸 if a person has trust of all people and he trusts no one
as, for outdegree, we are Subtarcting the value, so if anyone has outdegree > 0, it can never be equal to n - 1 and hence not a Judge

🔹So, our equation becomes, indegree + outdgree == n - 1
here, outdegree should be 0, and indegree == n - 1

🔸 Why n - 1?
as no of people = n and judge can be only 1 person, so n - 1 persons should trust him

*/

int findJudge(int n, vector<vector<int>> &trust)
{

    vector<int> degrees(n + 1, 0); // starting from index 1

    for (const auto &v : trust)
    {
        degrees[v[0]]--; // outdegree : trust to someone
        degrees[v[1]]++; // indegree : having trust of someone
    }

    for (int i = 1; i < degrees.size(); ++i)
    {
        // if indegree(having trust) == n - 1
        if (degrees[i] == n - 1)
            return i;
    }

    return -1;
}

int main()
{
    int n = 4;
    vector<vector<int>> trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};

    cout << findJudge(n, trust) << "\n";
    return 0;
}