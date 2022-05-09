// https://leetcode.com/problems/most-frequent-subtree-sum/

// https://leetcode.com/problems/most-frequent-subtree-sum/discuss/2022980/C%2B%2B-DFS-or-HashMap-or-Simple-code-explained-with-comments-%3A)

#include <iostream>
#include <map>
#include <algorithm>
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

unordered_map<int, int> cnt; // hashmap ot count frequencies
int mx = -1;                 // to keep track of highest frequency

int sumTree(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int sum = root->val + sumTree(root->left) + sumTree(root->right);
    mx = max(mx, ++cnt[sum]); // comparing and updating mx with count of current element (from the hashmap)

    return sum;
}

vector<int> findFrequentTreeSum(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;

    sumTree(root);

    for (auto &it : cnt)
    {
        if (it.second == mx) // those elements having frequency = to mx, push it in ans vector
            ans.push_back(it.first);
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);

    vector<int> ans = findFrequentTreeSum(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}