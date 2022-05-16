// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

// https://leetcode.com/problems/find-largest-value-in-each-tree-row/discuss/2045343/C%2B%2B-DFS-or-Super-Simple-or-Explained-with-comments-%3A)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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

vector<int> max_vals;

void levelOrder(TreeNode *root)
{

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        int mx = INT_MIN;

        while (size--)
        {
            TreeNode *t = q.front();
            q.pop();
            // while traversing, keep checking and updating the max value
            mx = max(mx, t->val);

            if (t->left)
                q.push(t->left);

            if (t->right)
                q.push(t->right);
        }
        // push the max value after each level
        max_vals.push_back(mx);
    }
}

vector<int> largestValues(TreeNode *root)
{
    if (root == NULL)
        return {};

    // max_vals.clear(); // as here it's declared globally

    levelOrder(root);

    return max_vals;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    vector<int> ans = largestValues(root);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}