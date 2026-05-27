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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root,ans);
        return ans;

    }

    int dfs(TreeNode* node, int &ans){
        if(!node) return 0;
        int left = max(0,dfs(node->left,ans));
        int right = max(0,dfs(node->right,ans));
        ans = max(ans, node->val + left + right);
        return (node->val + max(left,right));

    }
    int maxDown(TreeNode* node){
        if(!node) return 0;
        int left = max(0,maxDown(node->left));
        int right = max(0,maxDown(node->right));
        return max(0,node->val + max(left,right));
    }
};
