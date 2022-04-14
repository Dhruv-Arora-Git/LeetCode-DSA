// https://leetcode.com/problems/search-in-a-binary-search-tree/

// https://leetcode.com/problems/search-in-a-binary-search-tree/discuss/1946398/Simple-Iterative-Solution-C%2B%2B-(-)

#include <iostream>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int target)
{
    // if root is NULL, there is no tree, just return NULL
    if (root == NULL)
        return NULL;

    TreeNode *itr = root;

    while (itr != NULL)
    {

        if (itr->val == target) // target found, return that node
            return itr;

        if (itr->val < target) // go right
            itr = itr->right;
        else // go left
            itr = itr->left;
    }

    return NULL; // target not found
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode *target = searchBST(root, 5);

    cout << ((target != NULL) ? "Found " : "Not Found") << endl;

    return 0;
}