// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/2070072/C%2B%2B-DFS-%2B-Map-or-0ms-solution

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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

// hd -> vector(level, element)
map<int, vector<pair<int, int>>> mp;
void traverse(TreeNode *root, int level, int hd)
{
    if (root == NULL)
        return;

    mp[hd].push_back({level, root->val});

    traverse(root->left, level + 1, hd - 1);
    traverse(root->right, level + 1, hd + 1);
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{

    if (root == NULL)
        return {};

    vector<vector<int>> ans;

    traverse(root, 1, 0);

    for (auto &it : mp)
    {
        sort(it.second.begin(), it.second.end());

        vector<int> temp;

        for (auto &p : it.second)
            temp.push_back(p.second);

        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = verticalTraversal(root);

    for (vector<int> &v : ans)
    {
        for (int &i : v)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}