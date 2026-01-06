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

void check(TreeNode* root , int &maxi , int &height , int &h){
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty()){
        h++;
        int sum=0;
        int n= q.size();
        for(int i=0 ; i<n ; i++){
            TreeNode* temp = q.front();
            sum+=temp->val;
            q.pop();
            if(temp->left){
                q.push(temp->left);
                
            }
            if(temp->right){
                q.push(temp->right);
            }
       
        }
        if(sum>maxi){
            maxi=sum;
            height=h;
         
        }
    }

}
    int maxLevelSum(TreeNode* root) {
        int height=0;
        int h=0;
        int maxi= INT_MIN;
        check(root , maxi , height , h);
        return height;
        
    }
};