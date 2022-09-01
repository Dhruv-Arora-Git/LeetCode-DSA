// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

// https://leetcode.com/problems/count-good-nodes-in-binary-tree/discuss/2512210/C%2B%2B-void-DFS-with-Current-Max-and-Count

#include <iostream>
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

void dfs(TreeNode *root, int curMax, int &count)
{
    if (!root)
        return;

    if (root->val >= curMax)
        ++count;

    curMax = max(curMax, root->val);

    dfs(root->left, curMax, count);
    dfs(root->right, curMax, count);
}

int goodNodes(TreeNode *root)
{
    int count = 0;

    dfs(root, root->val, count);

    return count;
}

int main()
{
    /*
         3
        / \
       1   4
      /   / \
     3   1   5
    */
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    cout << goodNodes(root) << "\n";

    return 0;
}