// https://leetcode.com/problems/find-center-of-star-graph/

// https://leetcode.com/problems/find-center-of-star-graph/discuss/?currentPage=1&orderBy=most_votes&query=

#include <iostream>
#include <vector>

using namespace std;

// 1. Naive Approach :- Count the degrees (in + out) for each edge of graph, the edges which is having edges == n (no. of vertices - 1) is our answer
int findCenter(vector<vector<int>> &edges)
{

    int n = edges.size();
    vector<int> indeg(n + 2, 0);

    for (auto &v : edges)
    {
        ++indeg[v[0]];
        ++indeg[v[1]];
    }

    for (int i = 1; i < n + 2; ++i)
        if (indeg[i] == n)
            return i;

    return -1;
}

/*
    2. 1 Liner :- By reading the test cases, we can derive that our answer(vertex) is present in all the pairs.
    Ex - [ [1,2], [5,1], [1,3], [1,4] ] => 1 is present in all 4 pairs.
    So, Just compare first pair with second pair, the element which is present in both is our answer!
*/
int findCenter2(vector<vector<int>> &edges)
{
    return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0][1];
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};

    cout << findCenter(edges) << "\n";
    cout << findCenter2(edges) << "\n";

    return 0;
}