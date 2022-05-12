// https://leetcode.com/problems/path-sum/

// https://leetcode.com/problems/path-sum/discuss/2032545/C%2B%2B-3-different-Solutions-Discussed-%3A)

#include <iostream>
#include <unordered_set>

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

// 1. Insert all the values from root to leaf in a data structure, like a unordered_set<int> and check if it has targetSum or not
unordered_set<int> st;

void sum(TreeNode *root, int localSum, int targetSum)
{
    if (root == NULL)
        return;

    if ((root->left == NULL and root->right == NULL))
    {
        st.insert(localSum + root->val);
        return;
    }

    localSum += root->val;

    sum(root->left, localSum, targetSum);
    sum(root->right, localSum, targetSum);
}

bool hasPathSum1(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return false;
    // use st.clear() to clear the set, as now it is a global variable
    st.clear();

    sum(root, 0, targetSum);
    return st.find(targetSum) != st.end();
}

// 2. Use a bool variable flag to keep a check if targetSum is found or not
void pathSum2(TreeNode *root, int localSum, int targetSum, bool &flag)
{
    if (root == NULL)
        return;
    // condition for leaf node
    if (root->left == NULL and root->right == NULL)
    {
        if (root->val + localSum == targetSum)
        {
            flag = true;
            return;
        }
    }

    pathSum2(root->left, localSum + root->val, targetSum, flag);
    pathSum2(root->right, localSum + root->val, targetSum, flag);
}

bool hasPathSum2(TreeNode *root, int targetSum)
{
    bool flag = false;

    pathSum2(root, 0, targetSum, flag);

    return flag;
}

// 3. Keep subtracting root->val from targetSum in each call and if you reach at leaf node, check if it becomes 0, so, if it's a leaf node and  targetSum becomes 0, it means if we add all the values (root->val) in that path, it will be equal to targetSum and that's exactly what we want to find :)
bool hasPathSum3(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return false;

    if (root->left == NULL && root->right == NULL && targetSum - root->val == 0)
        return true;

    return hasPathSum3(root->left, targetSum - root->val) || hasPathSum3(root->right, targetSum - root->val);
}

int main()
{
    //       5
    //      / \
    //     4   8
    //    /   / \
    //   11  13  4
    //  /  \      \
    // 7    2      1

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    cout << hasPathSum1(root, 22) << "\n";
    cout << hasPathSum2(root, 22) << "\n";
    cout << hasPathSum3(root, 22) << "\n";
    return 0;
}