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
    bool isValidBST(TreeNode* root) {
        return isBST(root,LLONG_MAX,LLONG_MIN);
        
    }
    bool isBST(TreeNode* node,long long ul,long long ll){
        if(!node) return true;
        if(node->val <ul && node->val > ll ){
            return isBST(node->left,node->val,ll) && isBST(node->right,ul,node->val);
        }
        else return false;

    }
};
