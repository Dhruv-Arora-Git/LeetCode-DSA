// https://leetcode.com/problems/minimum-depth-of-binary-tree/

// https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/2029434/Simple-and-Clean-Code-C%2B%2B

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
int minDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (left == 0 || right == 0) // if any of both is zero, return non zero value
        return 1 + max(left, right);

    return 1 + min(left, right);
}

int main()
{
    // left skewed tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->left->left = new TreeNode(5);
    root->left->left->left->left->left = new TreeNode(6);

    cout << minDepth(root) << "\n";

    return 0;
}