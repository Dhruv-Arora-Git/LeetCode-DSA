// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/discuss/2048311/C%2B%2B-or-Very-Simple-DFS-or-Recursive-%3A)

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

TreeNode *ans = NULL;

void inorder(TreeNode *cloned, int target)
{
    if (cloned == NULL)
        return;

    inorder(cloned->left, target);

    if (cloned->val == target)
        ans = cloned;

    inorder(cloned->right, target);
}

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
    inorder(cloned, target->val);

    return ans;
}

int main()
{
    //   7
    //  / \
    // 4   3
    //    / \
    //   6   19

    TreeNode *original = new TreeNode(7);
    original->left = new TreeNode(3);
    original->right = new TreeNode(4);
    original->left->left = new TreeNode(19);
    original->left->right = new TreeNode(6);

    TreeNode *cloned = new TreeNode(7);
    cloned->left = new TreeNode(3);
    cloned->right = new TreeNode(4);
    cloned->left->left = new TreeNode(19);
    cloned->left->right = new TreeNode(6);

    TreeNode *answer = getTargetCopy(original, cloned, original->left);

    cout << answer->val << "\n";
    return 0;
}