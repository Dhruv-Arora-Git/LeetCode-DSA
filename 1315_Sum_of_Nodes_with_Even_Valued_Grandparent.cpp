// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/discuss/2163147/Just-Code-what-came-in-your-Mind-oror-Simple-DFS-C%2B%2B

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

int sumEvenGrandparent(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int sum = 0;

    if (root->val % 2 == 0)
    {
        if (root->left && root->left->left)
            sum += root->left->left->val;

        if (root->left && root->left->right)
            sum += root->left->right->val;

        if (root->right && root->right->right)
            sum += root->right->right->val;

        if (root->right && root->right->left)
            sum += root->right->left->val;
    }

    sum += sumEvenGrandparent(root->left);
    sum += sumEvenGrandparent(root->right);

    return sum;
}

int main()
{
    //          6
    //        /   \
    //       7     8
    //      / \   / \
    //     2   7 1   3
    //    /   / \     \
    //   9   1   4     5

    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(7);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->left->left->left = new TreeNode(9);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(5);

    cout << sumEvenGrandparent(root) << "\n";

    return 0;
}