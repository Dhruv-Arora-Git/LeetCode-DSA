// https://leetcode.com/problems/binary-tree-postorder-traversal/

// https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/2084510/C%2B%2B-Left-Right-Root-oror-Recursive-Postorder

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

void postorder(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
        return;

    postorder(root->left, arr);  // left
    postorder(root->right, arr); // right
    arr.push_back(root->val);    // root
}

vector<int> postorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<int> post;

    postorder(root, post);

    return post;
}

int main()
{
    //    1
    //     \
    //      2
    //     /
    //    3

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> post = postorderTraversal(root);

    for (int &i : post)
        cout << i << " ";

    cout << "\n";

    return 0;
}