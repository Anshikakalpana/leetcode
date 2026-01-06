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

    // function to perform level-order traversal and find
    // the level (height) with the maximum sum
    void check(TreeNode* root, int &maxi, int &minHeight, int & currHeight) {

        // queue for BFS (level-order traversal)
        queue<TreeNode*> q;
        q.push(root);

        // continue until all levels are processed
        while (!q.empty()) {

            // Increment level counter
            currHeight++;

            int sum = 0;            // sum of current level
            int n = q.size();       // number of nodes at current level

            // process all nodes of the current level
            for (int i = 0; i < n; i++) {

                // get front node
                TreeNode* temp = q.front();
                q.pop();

                // add node value to level sum
                sum += temp->val;

                // push left child if it exists
                if (temp->left) {
                    q.push(temp->left);
                }

                // push right child if it exists
                if (temp->right) {
                    q.push(temp->right);
                }
            }

            // update maximum sum and corresponding level
            if (sum > maxi) {
                maxi = sum;     // update max sum
                minHeight = currHeight;     // store level number
            }
        }
    }

    // main function to return the level with maximum sum
    int maxLevelSum(TreeNode* root) {

        int minHeight = 0;          // stores answer (level number)
        int currHeight = 0;               // tracks current level
        int maxi = INT_MIN;      // stores maximum level sum

     
        check(root, maxi, minHeight, currHeight);

        
        return minHeight;
    }
};
