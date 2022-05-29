// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/2088374/C%2B%2B-O(m-%2B-n)-Merge-2-Sorted-Arrays-oror-DFS

#include <iostream>
#include <vector>

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

// storing inorder traversal in a vector
void traverse(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
        return;

    traverse(root->left, arr);
    arr.push_back(root->val);
    traverse(root->right, arr);
}

// merge 2 sorted arrays
void merge(vector<int> &tree1, vector<int> &tree2, vector<int> &mergedTree)
{
    int i = 0, j = 0, k = 0;

    while (i < tree1.size() && j < tree2.size())
    {
        if (tree1[i] < tree2[j])
            mergedTree[k++] = tree1[i++];
        else
            mergedTree[k++] = tree2[j++];
    }

    while (i < tree1.size())
        mergedTree[k++] = tree1[i++];

    while (j < tree2.size())
        mergedTree[k++] = tree2[j++];
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> tree1;
    vector<int> tree2;
    traverse(root1, tree1);
    traverse(root2, tree2);

    int n = tree1.size(), m = tree2.size();

    vector<int> mergedTree(n + m);

    // merging both sorted vectors
    merge(tree1, tree2, mergedTree);

    return mergedTree;
}

int main()
{
    //    2
    //   / \
    //  1   4

    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    //    1
    //   / \
    //  0   3

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    vector<int> mergedTree = getAllElements(root1, root2);

    for (int &i : mergedTree)
        cout << i << " ";

    cout << "\n";

    return 0;
}
