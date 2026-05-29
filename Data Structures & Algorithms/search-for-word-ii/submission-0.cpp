class Solution {
public:
    struct TrieNode{
        TrieNode * children[26];
        string word;
        TrieNode(){
            word =  "";
            for(auto &c: children) c = nullptr;
        }
    };
    TrieNode*root = new TrieNode();
    void insert(string &word){
        TrieNode* node = root;
        for(auto ch: word){
            int idx = ch-'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>> &board, int r,int c, TrieNode* node,vector<string> &ans){
        char ch = board[r][c];
        if(ch=='#') return;
        node = node->children[ch-'a'];
        if(!node) return;
        if(node->word!=""){
            ans.push_back(node->word);
            node->word = "";
        }
        board[r][c] = '#';
        int dirs[4][2] = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        for(auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr >= 0 &&
               nr < board.size() &&
               nc >= 0 &&
               nc < board[0].size()) {

                dfs(board, nr, nc, node, ans);
            }
        }

        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word: words){
            insert(word);
        }
        vector<string> ans;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board,i,j,root,ans);
            }
        }
        return ans;
    }
};
