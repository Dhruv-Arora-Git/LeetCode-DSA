// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/discuss/2048263/C%2B%2B-using-set-or-Simple-Code-Explained-with-Comments-%3A)

#include <iostream>
#include <set>

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

set<int> vals; // it stores values in sorted order without duplicates

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    vals.insert(root->val);
    inorder(root->right);
}

int findSecondMinimumValue(TreeNode *root)
{

    inorder(root);

    auto itr = vals.begin(); // iterator at first element of set
    if (++itr == vals.end()) // check if second element exist or not
        return -1;           // if does not exist

    return *itr; // if exists, return that (*it means value at which iterator is / dereferencing)
}

int main()
{
    //   2
    //  / \
    // 2   5
    //    / \
    //   5   7
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->left->left = new TreeNode(7);

    cout << findSecondMinimumValue(root) << "\n";
    return 0;
}