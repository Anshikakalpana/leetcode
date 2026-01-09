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
    TreeNode* bfs(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> level;

        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            int n = q.size();
            level.clear();

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp);

                if (temp->left) {
                    parent[temp->left] = temp;
                    q.push(temp->left);
                }
                if (temp->right) {
                    parent[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }

        // Move deepest nodes up until they converge
        while (level.size() > 1) {
            unordered_set<TreeNode*> s;
            for (auto node : level) {
                s.insert(parent[node]);
            }
            level.assign(s.begin(), s.end());
        }

        TreeNode* ans = level[0];
        return ans;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return bfs(root);
    }
};
