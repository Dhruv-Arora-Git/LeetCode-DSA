// https://leetcode.com/problems/merge-two-binary-trees/

// https://leetcode.com/problems/merge-two-binary-trees/discuss/2031922/Easy-to-read-C%2B%2B-Recursive-Code-%3A)

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

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return NULL;

    int val1 = 0, val2 = 0;

    if (root1 != NULL)
        val1 = root1->val;
    if (root2 != NULL)
        val2 = root2->val;

    TreeNode *root = new TreeNode(val1 + val2);

    root->left = mergeTrees(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
    root->right = mergeTrees(root1 ? root1->right : NULL, root2 ? root2->right : NULL);

    return root;
}

// inorder traversal to print tree
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    // create two trees
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    // merge two trees
    TreeNode *root = mergeTrees(root1, root2);

    // print the merged tree
    inorder(root);

    return 0;
}