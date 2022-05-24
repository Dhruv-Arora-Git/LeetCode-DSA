// https://leetcode.com/problems/path-sum-iii/

// https://leetcode.com/problems/path-sum-iii/discuss/2070098/C%2B%2B-Traverse-on-each-node-and-check-for-it-Simple-%3A)

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

// For each node, three searches are needed, and the time cost for each search is the height of the tree, that's O(h). The worst case, Tree is like Linked List, h == n, O(h) = O(n); Best case, Tree is Balanced, which means height == logn, O(h) == O(logn);
// Since the number of nodes is n, for each node search is O(h) =>
// best case: O(nlogn)
// worst case: O(nn)

int total = 0;

void sum(TreeNode *root, int targetSum, long long currSum)
{
    if (root == NULL)
        return;

    currSum += root->val;

    if (currSum == targetSum)
        ++total;

    sum(root->left, targetSum, currSum);
    sum(root->right, targetSum, currSum);
}

void traverse(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return;
    sum(root, targetSum, 0);

    traverse(root->left, targetSum);
    traverse(root->right, targetSum);
}

int pathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return {};

    traverse(root, targetSum);

    return total;
}

int main()
{
    //        10
    //      /    \
    //     5      -3
    //    / \       \
    //   3   2      11
    //  / \   \
    // 3  -2   1
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    cout << pathSum(root, 8) << "\n";
    return 0;
}