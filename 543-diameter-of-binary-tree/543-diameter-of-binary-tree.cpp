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
    
    int  diameterFast(TreeNode* root,int &dia){
        
        if(root== NULL){ 
            return 0;
        }
        int left = diameterFast(root->left,dia);
        int right = diameterFast(root->right,dia);
        
        dia = max(dia,(left + right ));
        
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = INT_MIN;
        diameterFast(root,dia);
        return dia;
    }
};