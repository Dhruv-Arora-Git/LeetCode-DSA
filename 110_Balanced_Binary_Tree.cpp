// https://leetcode.com/problems/balanced-binary-tree/

// https://leetcode.com/problems/balanced-binary-tree/discuss/2008116/C%2B%2B-O(N)-Solution-or-checking-condition-while-calculating-depthheight-_

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

int helper(TreeNode *root, bool &flag)
{
    if (root == NULL)
        return 0;

    int left = helper(root->left, flag);
    int right = helper(root->right, flag);

    // checking for balance
    if (abs(left - right) > 1)
    {
        flag = false;
        return 0;
    }

    // calculating height
    return max(left, right) + 1;
}

bool isBalanced(TreeNode *root)
{
    bool ans = true;

    helper(root, ans);

    return ans;
}

int main()
{
    //    1
    //  2   3
    // 4 5 6 7
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);
    p->right->left = new TreeNode(6);
    p->right->right = new TreeNode(7);

    cout << isBalanced(p) << endl;
    return 0;
}