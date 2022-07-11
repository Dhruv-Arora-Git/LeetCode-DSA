// https://leetcode.com/problems/binary-tree-right-side-view/

// https://leetcode.com/problems/binary-tree-right-side-view/discuss/2267129/Simple-BFS-Solution-C%2B%2B-or-Explained-with-Comments

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

vector<int> rightSideView(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;

    // BFS
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        int right = -1;

        while (size--)
        {
            TreeNode *t = q.front();
            q.pop();

            right = t->val; // it's last value will be of right most node
            // ex - 2 3, it will get 3 at last,
            // which is right most node of a particular level

            if (t->left)
                q.push(t->left);

            if (t->right)
                q.push(t->right);
        }

        ans.push_back(right);
    }

    return ans;
}

int main()
{
    //    1
    //   / \
    //  2   3
    //   \   \
    //    5   4

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> ans = rightSideView(root);

    for (const int &a : ans)
        cout << a << " ";
    cout << "\n";

    return 0;
}