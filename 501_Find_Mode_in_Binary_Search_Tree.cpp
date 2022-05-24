// https://leetcode.com/problems/find-mode-in-binary-search-tree/

// https://leetcode.com/problems/find-mode-in-binary-search-tree/discuss/2069990/C%2B%2B-HashMap-Solution-or-Simple-to-understand

#include <iostream>
#include <unordered_map>
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

int mx_freq = 0;
unordered_map<int, int> mp;

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    // checking if the new freq max or not
    mx_freq = max(mx_freq, ++mp[root->val]);

    inorder(root->left);
    inorder(root->right);
}

vector<int> findMode(TreeNode *root)
{
    if (root == NULL)
        return {};

    inorder(root);
    vector<int> ans;

    for (auto it : mp)
    {
        if (it.second == mx_freq) // all the nodes having frequency == mx_frequency
            ans.push_back(it.first);
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(2);

    vector<int> ans = findMode(root);

    for (int i : ans)
        cout << i << " ";

    cout << "\n";

    return 0;
}