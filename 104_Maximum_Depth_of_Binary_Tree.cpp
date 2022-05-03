// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/2004522/A-Simple-2-Liner-oror-Recursion-oror-Explained!-C%2B%2B

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

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
    TreeNode *p = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5));

    cout << maxDepth(p) << "\n";
    return 0;
}