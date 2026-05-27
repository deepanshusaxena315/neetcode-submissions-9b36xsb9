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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        preorder(root,ans);
        return ans;
    }

    void preorder(TreeNode* node,string &ans){
        if(!node){
            ans+= "N,";
            return;
        }
        
        ans += to_string(node->val) + ",";
        preorder(node->left,ans);
        preorder(node->right,ans);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string cur;
        vector<string> nodes;
        for(auto &c: data){
            if(c==','){
                nodes.push_back(cur);
                cur.clear();
            }
            else{
                cur += c;
            }
        }
        int idx = 0;
        return build(nodes,idx);
        
    }

    TreeNode* build(vector<string> &nodes,int &idx){
        // int n = nodes.size();
        // if(idx==n) return;
        if(nodes[idx]=="N"){
            idx++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(nodes[idx++]));
        node->left = build(nodes,idx);
        node->right = build(nodes,idx);
        return node;
    }
};
