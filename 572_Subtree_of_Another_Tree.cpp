// https://leetcode.com/problems/subtree-of-another-tree/

// https://leetcode.com/problems/subtree-of-another-tree/discuss/2022439/My-Naive-Solution-or-Clean-and-Easy-to-understand-%3A)-C%2B%2B

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

bool isSameTree(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (
        root1->val == root2->val && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right))
        return true;
    else
        return false;
}

void inorder(TreeNode *root, TreeNode *subRoot, bool &flag)
{
    if (root == NULL)
        return;

    inorder(root->left, subRoot, flag);

    if (isSameTree(root, subRoot))
    {
        flag = true;
        return;
    }

    inorder(root->right, subRoot, flag);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    bool flag = false;

    inorder(root, subRoot, flag);

    return flag;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode *subRoot = new TreeNode(2);
    subRoot->left = new TreeNode(4);
    subRoot->right = new TreeNode(5);

    cout << isSubtree(root, subRoot) << "\n";
    return 0;
}