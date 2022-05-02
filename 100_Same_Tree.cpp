// https://leetcode.com/problems/same-tree/

// https://leetcode.com/problems/same-tree/discuss/2002339/clean-understandable-and-concise-code-C%2B%2B

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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    return (
        p->val == q->val &&             // check value
        isSameTree(p->left, q->left) && // it's left
        isSameTree(p->right, q->right)  // and it's right
    );
}

int main()
{
    TreeNode *p = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5));
    TreeNode *q = new TreeNode(1, new TreeNode(2, NULL, new TreeNode(4)), new TreeNode(5));

    cout << isSameTree(p, q) << "\n";

    return 0;
}