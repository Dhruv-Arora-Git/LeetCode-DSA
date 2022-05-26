// https://leetcode.com/problems/average-of-levels-in-binary-tree/

// https://leetcode.com/problems/average-of-levels-in-binary-tree/discuss/2076749/C%2B%2B-Simple-BFS-Solution-%3A)

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

vector<double> averageOfLevels(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<double> avg;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {

        int size = q.size();
        double sum = 0; // sum of each level

        for (int i = 0; i < size; ++i)
        {
            TreeNode *t = q.front();
            q.pop();

            sum += t->val;

            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        avg.push_back(sum / size);
    }

    return avg;
}

int main()
{
    //    3
    //   / \
    //  9  20
    //     / \
    //    15  7

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<double> avg = averageOfLevels(root);

    for (auto &a : avg)
        cout << a << " ";
    cout << "\n";
    return 0;
}