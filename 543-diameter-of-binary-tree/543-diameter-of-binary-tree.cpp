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
    int op3 = INT_MIN;
    int  diameterFast(TreeNode* root){
        
        if(root== NULL){ 
            return 0;
        }
        int left = diameterFast(root->left);
        int right = diameterFast(root->right);
        
        op3 = max(op3,(left + right ));
        
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameterFast(root);
        return op3;
    }
};