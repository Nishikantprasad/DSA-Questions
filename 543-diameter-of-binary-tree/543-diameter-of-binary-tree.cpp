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
    
    int  diameterFast(TreeNode* root,int &op3){
        
        if(root== NULL){ 
            return 0;
        }
        int left = diameterFast(root->left,op3);
        int right = diameterFast(root->right,op3);
        
        op3 = max(op3,(left + right ));
        
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int op3 = INT_MIN;
        diameterFast(root,op3);
        return op3;
    }
};