#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    queue<TreeNode *> q;

    q.push(root);

    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        level++;

        vector<int> data;

        while (size--)
        {
            TreeNode *t = q.front();
            q.pop();
            data.push_back(t->val);

            if (t->left)
                q.push(t->left);

            if (t->right)
                q.push(t->right);
        }

        // when the level is even, just reverse the order
        if (level % 2 == 0)
            reverse(data.begin(), data.end());

        ans.push_back(data);
    }

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

    vector<vector<int>> ans = zigzagLevelOrder(p);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}