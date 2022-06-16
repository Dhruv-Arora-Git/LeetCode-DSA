// https://leetcode.com/problems/deepest-leaves-sum/

// https://leetcode.com/problems/deepest-leaves-sum/discuss/2159581/C%2B%2B-BFS-Level-Order-Traversal-or-Explained-with-Comments

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int bfs(TreeNode *root)
{
    int sum = 0;

    queue<TreeNode *> q;
    q.push(root);

    // to store the last level nodes
    vector<int> v;

    // BFS
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp; // to store nodes at each level

        while (size--)
        {
            TreeNode *t = q.front();
            q.pop();

            temp.push_back(t->val);

            if (t->left)
                q.push(t->left);

            if (t->right)
                q.push(t->right);
        }
        // at last temp will have deepest leaf nodes, assigning it to v
        v = temp;
    }

    // adding all values
    for (int &i : v)
        sum += i;

    return sum;
}

int deepestLeavesSum(TreeNode *root)
{
    return bfs(root);
}

int main()
{
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6
    //    /         \
    //   7           8

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    cout << deepestLeavesSum(root) << "\n";

    return 0;
}