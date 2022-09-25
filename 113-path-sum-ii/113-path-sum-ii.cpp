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
    void dfs(TreeNode* root, vector<vector<int>>&ans,vector<int> &path,int targetSum){
        if(root == NULL){
            return ;
        }
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && targetSum == root->val){
            ans.push_back(path);
        }
        dfs(root->left, ans, path , targetSum - root->val);
        dfs(root->right , ans , path , targetSum - root->val);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, ans , path, targetSum);
        return ans;
    }
};