// https://leetcode.com/problems/sum-of-left-leaves/

// https://leetcode.com/problems/sum-of-left-leaves/discuss/2029668/DFS-with-1-condition-or-C%2B%2B

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

void sumLeft(TreeNode *root, int &sum)
{
    if (root == NULL)
        return;

    // condition for left leaf
    if (root->left != NULL)
        if (root->left->left == NULL && root->left->right == NULL)
            sum += root->left->val;

    sumLeft(root->left, sum);
    sumLeft(root->right, sum);
}

int sumOfLeftLeaves(TreeNode *root)
{
    if ((root == NULL) or (root->left == NULL && root->right == NULL))
        return {};

    int sum = 0;

    sumLeft(root, sum);

    return sum;
}

int main()
{
    //    3
    //   / \
    //  9  15
    //     / \
    //    20  7

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sumOfLeftLeaves(root) << "\n";

    return 0;
}