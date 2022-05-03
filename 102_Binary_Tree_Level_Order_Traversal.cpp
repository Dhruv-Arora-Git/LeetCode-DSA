// https://leetcode.com/problems/binary-tree-level-order-traversal/

// https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/2005091/C%2B%2B-Solution-using-queue-Iterative-or-0ms-or-Explained-with-Comments

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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        // taking the size of queue at each iteration, as number of children changes with each iteration
        int size = q.size();

        vector<int> data;

        while (size--)
        {
            TreeNode *t = q.front();
            q.pop(); // taking out first node from queue

            data.push_back(t->val);

            if (t->left != NULL) // if it's left exists, push it in the queue
                q.push(t->left);
            if (t->right != NULL) // if it's right exists, push it in the queue
                q.push(t->right);
        }

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

    vector<vector<int>> ans = levelOrder(p);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}