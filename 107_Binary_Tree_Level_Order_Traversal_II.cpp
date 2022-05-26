// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/discuss/2076708/C%2B%2B-Simple-normal-BFS-Solution-)

#include <iostream>
#include <vector>
#include <queue>

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

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<vector<int>> ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        vector<int> v;
        while (size--)
        {
            TreeNode *t = q.front();
            q.pop();

            v.push_back(t->val);

            if (t->left)
                q.push(t->left);

            if (t->right)
                q.push(t->right);
        }
        ans.insert(ans.begin(), v); // or ans.push_back(v);
    }

    // reverse(ans.begin(), ans.end()); if you want to use push_back(v) instead of insert

    return ans;
}

int main()
{
    //        1
    //      /  \
    //     10   4
    //    /    / \
    //   3    7   9
    //  / \  /     \
    // 12  8 6      2

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(8);
    root->right->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(2);

    vector<vector<int>> ans = levelOrderBottom(root);

    for (auto &v : ans)
    {
        for (auto &i : v)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}