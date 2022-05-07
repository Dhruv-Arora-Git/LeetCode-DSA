// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/2016547/Explained-Brute-Force-and-Optimal-Approach-O(n)-C%2B%2B

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

bool findPath(TreeNode *root, TreeNode *n, vector<TreeNode *> &path)
{
    if (root == NULL)
        return false;

    path.push_back(root);

    if (root == n)
        return true;

    if (findPath(root->left, n, path) || findPath(root->right, n, path))
        return true;

    path.pop_back();
    return false;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> path1, path2;

    if (!findPath(root, p, path1) || !findPath(root, q, path2))
        return NULL;

    TreeNode *ans = NULL;

    for (int i = 0; i < min(path1.size(), path2.size()); ++i)
    {
        if (path1[i] == path2[i])
            ans = path1[i];
    }

    return ans;
}

TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    if (root == p or root == q)
        return root;

    TreeNode *left = lowestCommonAncestor2(root->left, p, q);
    TreeNode *right = lowestCommonAncestor2(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    if (left == NULL && right == NULL)
        return NULL;

    if (left != NULL)
        return left;
    else
        return right;
}

int main()
{
    // same as leetcode
    TreeNode *root = new TreeNode(3, new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))), new TreeNode(1, new TreeNode(0), new TreeNode(8)));

    TreeNode *p = root->left;
    TreeNode *q = root->right;

    // cout << p->val << " " << q->val << "\n";
    TreeNode *ans = lowestCommonAncestor2(root, p, q);

    cout << ans->val << "\n";
    return 0;
}