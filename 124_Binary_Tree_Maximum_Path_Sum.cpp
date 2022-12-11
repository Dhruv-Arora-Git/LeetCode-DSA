// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

// https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/2902056/c-0-ms-approach-discussed-postorder-dfs-clean-code/

#include <iostream>
#include <algorithm>
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

int maxSum = -1e9;

int pathSum(TreeNode *root)
{
    if (!root)
        return 0;

    int leftPathSum = pathSum(root->left);
    int rightPathSum = pathSum(root->right);

    int currSum = root->val + leftPathSum + rightPathSum;

    maxSum = max({maxSum,
                  currSum,
                  root->val,
                  root->val + max(leftPathSum, rightPathSum)});

    return max(
        root->val,
        root->val + max(leftPathSum, rightPathSum));
}

int maxPathSum(TreeNode *root)
{
    return max(
        pathSum(root),
        maxSum);
}

int main()
{
    //   -10
    //   /  \
    //  9   20
    //      / \
    //     15  7

    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxPathSum(root) << "\n";

    return 0;
}