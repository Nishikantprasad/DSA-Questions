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
    void solve(TreeNode* root,unordered_set<int>set ,int &ans){
        if(root == NULL){
            return ;
        }
        if(set.find(root->val) != set.end()){
            set.erase(root->val);
        }
        else{
            set.insert(root->val);
        }
        if(root->right == NULL && root->left ==  NULL){
            if(set.size()<=1){
                ans++;
            }
            return ;
        }
        if(root->left)
            solve(root->left,set,ans);
        if(root->right)
            solve(root->right,set,ans);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> set;
        int  ans =0;
        solve(root, set, ans);
        return ans;
    }
};