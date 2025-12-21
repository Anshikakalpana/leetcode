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
void check(TreeNode* root , int maxi , int &ans){
                  if(root==NULL) return ;
                  if(root->val >=maxi){
                    ans++;
                    if(root->left) check(root->left , root->val ,ans );
                    if(root->right) check(root->right , root->val ,ans);
                  }
                  else{
                    if(root->left) check(root->left , maxi ,ans);
                    if(root->right) check(root->right , maxi ,ans);
}
}
    int goodNodes(TreeNode* root) {
        int ans=0;
       check(root , INT_MIN ,ans);
        return ans;
        
    }
};