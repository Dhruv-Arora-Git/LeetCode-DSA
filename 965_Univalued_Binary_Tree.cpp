// https://leetcode.com/problems/univalued-binary-tree/

// https://leetcode.com/problems/univalued-binary-tree/discuss/2079540/C%2B%2B-Simple-DFS-Solution-%3A)

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

// Traverse the tree and check all the nodes having the same value as root.
bool check(TreeNode *root, int chk_val)
{
    if (root == NULL)
        return true;

    return (root->val == chk_val) && check(root->left, chk_val) && check(root->right, chk_val);
}

bool isUnivalTree(TreeNode *root)
{
    return check(root, root->val);
}

int main()
{
    //      1
    //     / \
    //    1   1
    //   / \
    //  1   1

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);

    cout << boolalpha << isUnivalTree(root) << "\n";
    return 0;
}