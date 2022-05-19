// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/2050776/C%2B%2B-Same-as-2-Sum-II-%3A)

#include <iostream>
#include <vector>

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

vector<int> vals;

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    vals.push_back(root->val);
    inorder(root->right);
}

bool findTarget(TreeNode *root, int k)
{
    // vals.clear(); // because we are using a global vector here, but on LeetCode it's a class variable

    // inorder traversal gives sorted order
    inorder(root);

    // 2 pointer approach - same as 2 Sum II
    int i = 0, j = vals.size() - 1;

    while (i < j)
    {
        int sum = vals[i] + vals[j];

        if (sum == k)
            return true;

        if (sum < k)
            ++i;
        else
            --j;
    }

    return false;
}

int main()
{
    //     5
    //    / \
    //   3   6
    //  / \   \
    // 2   4   7

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    // 1 = true, 0 = false
    cout << findTarget(root, 9) << "\n";

    return 0;
}