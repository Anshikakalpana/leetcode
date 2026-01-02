/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    void check(TreeNode* root, int targetSum, long long &sum) {
        if (root == nullptr) return;

        sum += root->val;
        if (sum == targetSum) ans++;

        check(root->left, targetSum, sum);
        check(root->right, targetSum, sum);

        sum -= root->val; // backtrack
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;

       long long sum = 0;
        check(root, targetSum, sum);

        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ans;
    }
};
