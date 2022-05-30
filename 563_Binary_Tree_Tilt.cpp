// https://leetcode.com/problems/binary-tree-tilt/

// https://leetcode.com/problems/binary-tree-tilt/discuss/2069951/C%2B%2B-Simple-Inorder-Traversal-or-DFS

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

int tilt = 0;

// postorder traversal (left, right, root)
int dfs(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = dfs(root->left);

    int right = dfs(root->right);

    // calculate tilt for each node
    tilt += abs(right - left);

    // root value + sum of left nodes + sum of right nodes
    return root->val + left + right;
}

int findTilt(TreeNode *root)
{
    dfs(root);

    return tilt;
}

int main()
{
    //     4
    //    / \
    //   2   9
    //  / \   \
    // 3   5   7

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << findTilt(root) << "\n";

    return 0;
}