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
    void bfs(TreeNode* root, int level, vector<vector<int>>& ans) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> v;
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* head = q.front();
                q.pop();

                v.push_back(head->val);

                // always normal BFS order
                if (head->left) q.push(head->left);
                if (head->right) q.push(head->right);
            }

           
            if (level % 2 == 1) {
                reverse(v.begin(), v.end());
            }

            ans.push_back(v);
            level++;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        bfs(root, 0, ans);
        return ans;
    }
};
