// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/3088989/C%2B%2B-Parent-Mapping-%2B-BFS-oror-Comment-Added

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// ---------------------------------------------------
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// ---------------------------------------------------

void dfs(TreeNode *parent, TreeNode *child, unordered_map<TreeNode *, TreeNode *> &mapping)
{
    if (child == NULL)
        return;

    mapping[child] = parent;

    dfs(child, child->left, mapping);
    dfs(child, child->right, mapping);
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> mapping;
    dfs(NULL, root, mapping);

    // to keep the note of visited nodes
    unordered_set<TreeNode *> visited;

    visited.insert(target);

    // start BFS from target
    queue<TreeNode *> q;
    q.push(target);

    int level = 0;
    while (!q.empty())
    {
        int size = q.size();

        if (level == k)
            break;

        while (size--)
        {
            TreeNode *t = q.front();
            q.pop();

            if (t->left && visited.find(t->left) == visited.end())
            {
                q.push(t->left);
                visited.insert(t->left);
            }

            if (t->right && visited.find(t->right) == visited.end())
            {
                q.push(t->right);
                visited.insert(t->right);
            }
            // also push the parent in the queue
            TreeNode *parent = mapping[t];

            if (parent != NULL && visited.find(parent) == visited.end())
            {
                q.push(parent);
                visited.insert(parent);
            }
        }
        ++level;
    }

    vector<int> ans;

    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
}

int main()
{
    //        3 <- root
    //      /  \
    //     5    1 <- startNode
    //    / \  / \
    //   6  2 0   8
    //     / \
    //    7   4

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *startNode = root->left;
    int k = 2;

    vector<int> ans = distanceK(root, startNode, k);

    for (int &i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}