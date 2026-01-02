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
 void dfs(TreeNode* root1, int targetSum , vector<vector<int>>&ans , vector<int>&temp , int sum){
    
    if(root1==NULL){
        return;
    }

    sum= sum+root1->val;
    temp.push_back(root1->val);

     if(sum==targetSum && root1->left==NULL &&root1->right==NULL) {
        ans.push_back(temp);


     }
     dfs(root1->left , targetSum , ans , temp , sum );
     dfs(root1->right , targetSum , ans , temp , sum );
     sum-=root1->val;
     temp.pop_back();


   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>>ans ;
        vector<int>temp;
        dfs(root ,targetSum , ans , temp ,0);
         return ans;
    }
};