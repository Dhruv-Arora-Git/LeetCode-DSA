// https://leetcode.com/problems/cousins-in-binary-tree/

// https://leetcode.com/problems/cousins-in-binary-tree/discuss/2029592/2-Approaches-%3A-BFS-and-DFS-or-C%2B%2B

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

// 1st approach: BFS
vector<pair<TreeNode *, int>> ans;

void findDepth(TreeNode *root, TreeNode *parent, int depth, int x, int y)
{
    if (root == NULL || ans.size() == 2)
        return;

    if (root->val == x || root->val == y)
        ans.push_back({parent, depth});

    findDepth(root->left, root, depth + 1, x, y);
    findDepth(root->right, root, depth + 1, x, y);
}

bool isCousins(TreeNode *root, int x, int y)
{
    findDepth(root, NULL, 0, x, y);

    return ans[0].first != ans[1].first && ans[0].second == ans[1].second;
}

// 2nd approach: DFS
bool check(vector<int> &v, int x, int y)
{

    bool check1 = false, check2 = false;

    for (int &i : v)
    {
        if (i == x)
            check1 = true;
        if (i == y)
            check2 = true;
    }
    return (check1 && check2);
}
bool levelOrder(TreeNode *root, int x, int y)
{
    if (root == NULL)
        return 0;

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

            if (t->left != NULL && t->right != NULL)
            {
                if ((t->left->val == x and t->right->val == y) or (t->left->val == y and t->right->val == x))
                    return false;
            }

            v.push_back(t->val);

            if (t->left)
                q.push(t->left);

            if (t->right)
                q.push(t->right);
        }
        if (check(v, x, y))
            return true;
    }

    return false;
}

bool isCousins2(TreeNode *root, int x, int y)
{

    return levelOrder(root, x, y);
}

int main()
{
    //    1
    //   / \
    //  2   3
    //     / \
    //    4   5

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << isCousins(root, 2, 4) << "\n";

    return 0;
}