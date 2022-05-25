// https://leetcode.com/problems/even-odd-tree/

// https://leetcode.com/problems/even-odd-tree/discuss/2073489/Beginner-Friendly-Code-oror-BFS-oror-C%2B%2B

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

bool isIncreasing(vector<int> &arr)
{
    if (arr.size() == 1)
    {
        if (arr[0] % 2 != 0)
            return true;
        else
            return false;
    }

    for (int i = 0; i < arr.size() - 1; ++i)
    {
        if (arr[i] % 2 == 0 || arr[i + 1] % 2 == 0)
            return false;

        if (arr[i] >= arr[i + 1])
            return false;
    }

    return true;
}

bool isDecreasing(vector<int> &arr)
{

    if (arr.size() == 1)
    {
        if (arr[0] % 2 == 0)
            return true;
        else
            return false;
    }

    for (int i = 0; i < arr.size() - 1; ++i)
    {
        if (arr[i] % 2 != 0 || arr[i + 1] % 2 != 0)
            return false;

        if (arr[i] <= arr[i + 1])
            return false;
    }

    return true;
}

bool isEvenOddTree(TreeNode *root)
{
    if (root == NULL)
        return false;

    queue<TreeNode *> q;
    q.push(root);

    bool flag = false;
    int level = -1;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> data;

        level++;

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

        // level is odd
        if (level % 2 != 0)
        {
            // node values are even and in decreasing order
            if (isDecreasing(data))
                flag = true;
            else
                return false;
        }
        // level is even
        else
        {
            // node values are odd and in increasing order
            if (isIncreasing(data))
                flag = true;
            else
                return false;
        }
    }

    return flag;
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

    cout << boolalpha << isEvenOddTree(root) << "\n";
    return 0;
}