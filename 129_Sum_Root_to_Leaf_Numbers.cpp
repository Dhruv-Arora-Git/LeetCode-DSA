// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/2064535/2-Cool-Recursive-Solutions-!-C%2B%2B

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

// 1. Stored all the paths in a vector of string and then converted it to an integer and added to answer.
vector<string> paths;

void inorder(TreeNode *root, string path)
{
    if (root == NULL)
    {

        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        path += (root->val + '0');

        paths.push_back(path);
        return;
    }

    path += (root->val + '0');
    inorder(root->left, path);

    inorder(root->right, path);
}

int sumNumbers(TreeNode *root)
{
    int ans = 0;

    inorder(root, "");

    for (const string &s : paths)
        ans += stoi(s);

    return ans;
}

// 2. making the number from digits itself and returning the sum.
int inorder(TreeNode *root, int curr_sum)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL) // leaf node
        return curr_sum * 10 + root->val;

    // left sum + right sum
    return inorder(root->left, curr_sum * 10 + root->val) + inorder(root->right, curr_sum * 10 + root->val);
}

int sumNumbers2(TreeNode *root)
{
    return inorder(root, 0);
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    cout << sumNumbers(root) << "\n";
    cout << sumNumbers2(root) << "\n";
    return 0;
}