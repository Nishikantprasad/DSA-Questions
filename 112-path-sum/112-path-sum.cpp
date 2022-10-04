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
    void dfs(TreeNode* root, bool &ans,int currSum , int targetSum){
        if(root == NULL){
            return;
        }
        currSum += root->val;
        if(root->left ==NULL && root->right == NULL && currSum == targetSum){
            ans = true;
        }
        dfs(root->left,ans, currSum,targetSum);
        dfs(root->right, ans , currSum , targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans= false;
        dfs(root, ans , 0, targetSum);
        return ans;
    }
};