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
    int preIdx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> hash;
        for(int i=0;i<inorder.size();i++){
            hash[inorder[i]] = i;
        } 
        return build(preorder,inorder,hash,0,preorder.size()-1);
    }
    TreeNode* build(vector<int> &preorder, vector<int> &inorder,unordered_map<int,int> mp,int left,int right){
        if(left>right) return nullptr;
        int nodeVal = preorder[preIdx++];
        TreeNode* node = new TreeNode(nodeVal);
        int idx = mp[nodeVal];
        node->left = build(preorder,inorder,mp,left,idx-1);
        node->right = build(preorder,inorder,mp,idx+1,right);
        return node;

    }
};
