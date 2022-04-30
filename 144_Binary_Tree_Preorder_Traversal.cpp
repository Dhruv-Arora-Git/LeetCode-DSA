// https://leetcode.com/problems/binary-tree-preorder-traversal/

// https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/1994308/3-Different-Solutions-or-Iterative-%2B-Recursive-o()o-C%2B%2B

#include <iostream>
#include <vector>
#include <stack>

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

// 1. Using recursion with global array
vector<int> traverse;
void helper(TreeNode *root)
{
    if (root == NULL)
        return;
    traverse.push_back(root->val);

    helper(root->left);
    helper(root->right);
}

vector<int> preorderTraversal1(TreeNode *root)
{
    helper(root);

    return traverse;
}

// 2 using local vector (not in arguments / global array) and recursion
vector<int> helper2(TreeNode *root)
{
    if (root == NULL)
    {
        vector<int> v;
        return v;
    }
    vector<int> arr;
    arr.push_back(root->val);

    vector<int> left = helper2(root->left);
    vector<int> right = helper2(root->right);

    left.insert(left.end(), right.begin(), right.end());
    arr.insert(arr.end(), left.begin(), left.end());

    return arr;
}

vector<int> preorderTraversal2(TreeNode *root)
{
    vector<int> arr;

    arr = helper2(root);

    return arr;
}

// 3 iterative
vector<int> preorderTraversal3(TreeNode *root)
{

    vector<int> arr;

    if (root == NULL)
        return arr;

    stack<TreeNode *> stk;

    TreeNode *t = root;

    while (t != NULL or !stk.empty())
    {
        if (t != NULL)
        {
            arr.push_back(t->val); // root
            stk.push(t);
            t = t->left; // left
        }
        else
        {
            t = stk.top();
            stk.pop();
            t = t->right; // right
        }
    }

    return arr;
}

int main()
{
    // [1,2,3,4,5,6,7,null]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "1. Using recursion with global array:\n";
    vector<int> arr = preorderTraversal1(root);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << "\n2. Using local vector (not in arguments / global array) and recursion:\n";
    vector<int> arr2 = preorderTraversal2(root);
    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << " ";

    cout << "\n3. Iterative:\n";
    vector<int> arr3 = preorderTraversal3(root);
    for (int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << " ";

    return 0;
}