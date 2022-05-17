// https://leetcode.com/problems/validate-binary-search-tree/

// https://leetcode.com/problems/validate-binary-search-tree/discuss/2048086/C%2B%2B-2-Simple-Solutions-Discussed-or-DFS-)

#include <iostream>
#include <vector>
#include <climits>

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

// LOGIC: Store the values in a vector and check if it's sorted or not (why this works ?: inorder traversal of BST gives values in sorted order) class Solution
void inorder(TreeNode *root, vector<int> &vals)
{
    if (root == NULL)
        return;

    inorder(root->left, vals);
    vals.push_back(root->val);
    inorder(root->right, vals);
}

bool isSorted(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i + 1] <= v[i])
            return false;
    }
    return true;
}

bool isValidBST1(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<int> v;
    inorder(root, v);

    return isSorted(v);
}

// LOGIC: for left side, see if it's values are less than root; for right side, see if it's values are greater than root.
// (don't take int mn and mx, as INT_MIN and INT_MAX values are in test cases, you will get WA for that, instead use long long)

bool check(TreeNode *root, long long mn, long long mx)
{
    if (root == NULL)
        return true;

    return (root->val > mn && root->val < mx) && check(root->left, mn, root->val) && check(root->right, root->val, mx);
}

bool isValidBST2(TreeNode *root)
{
    return check(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    //   5
    //  / \
    // 1   4
    //    / \
    //   3   6
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->left->left = new TreeNode(6);

    cout << isValidBST1(root) << "\n";
    cout << isValidBST2(root) << "\n";
    return 0;
}