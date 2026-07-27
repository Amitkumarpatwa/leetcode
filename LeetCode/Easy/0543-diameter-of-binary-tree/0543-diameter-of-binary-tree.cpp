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
    int maxDia=0;
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dia=level(root->left)+level(root->right);
        maxDia=max(dia,maxDia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxDia;
    }
};