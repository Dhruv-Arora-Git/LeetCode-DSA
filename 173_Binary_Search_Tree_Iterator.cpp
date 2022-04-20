#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
private:
    vector<int> data;
    int index = 0;

    void helper(TreeNode *root)
    {
        // inorder traversal, storing all elements in a vector
        if (root == NULL)
            return;

        helper(root->left);

        data.push_back(root->val);

        helper(root->right);
    }

public:
    BSTIterator(TreeNode *root)
    {
        helper(root);
    }

    int next()
    {
        // return the data, and increment index
        return data[index++];
    }

    bool hasNext()
    {
        // if index is in the range of vector, return true
        if (index < data.size())
            return true;

        return false;
    }
};

int main()
{

    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator *obj = new BSTIterator(root);
    int nextData = obj->next();
    bool hasNext = obj->hasNext();

    cout << "Element = " << nextData << "\n";
    cout << "Has next? : " << (hasNext ? "Yes" : "No") << "\n";
    return 0;
}