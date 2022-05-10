// https://leetcode.com/problems/symmetric-tree/

// https://leetcode.com/problems/symmetric-tree/discuss/2025214/Simple-Recursive-C%2B%2B-Solution-or-Explained-with-comments-%3A)

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

bool isSame(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->val == root2->val)            // checking the value
           && isSame(root1->right, root2->left)  // root1's right == root2's left
           && isSame(root1->left, root2->right); // root1's left == root2's right
}

bool isSymmetric(TreeNode *root)
{
    // handling case of root == NULL or root is the only node in tree
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return true;

    return isSame(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));

    cout << isSymmetric(root) << "\n";
    return 0;
}