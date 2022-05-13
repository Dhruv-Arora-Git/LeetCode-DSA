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

vector<vector<int>> ans;
void paths(TreeNode *root, int targetSum, vector<int> v)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL && targetSum - root->val == 0)
    {
        v.push_back(root->val);
        ans.push_back(v);
        return;
    }

    v.push_back(root->val);

    paths(root->left, targetSum - root->val, v);
    paths(root->right, targetSum - root->val, v);
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return {};
    vector<int> v;
    paths(root, targetSum, v);

    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int>> ans = pathSum(root, 22);

    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}