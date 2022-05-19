// https://leetcode.com/problems/range-sum-of-bst/

// https://leetcode.com/problems/range-sum-of-bst/discuss/2053718/C%2B%2B-simple-inorder-traversal-%3A)

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

int sum = 0;

void inorder(TreeNode *root, int low, int high)
{
    if (root == NULL)
        return;

    inorder(root->left, low, high);

    if (root->val >= low && root->val <= high)
        sum += root->val;

    inorder(root->right, low, high);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    inorder(root, low, high);

    return sum;
}

int main()
{
    //     10
    //    /  \
    //   5    15
    //  / \    \
    // 3   7   18

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    cout << rangeSumBST(root, 7, 15) << "\n";
    return 0;
}