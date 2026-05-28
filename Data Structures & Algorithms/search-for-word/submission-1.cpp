class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(findWord(board,word,0,i,j,visited)) return true;
            }
        }
        return false;
    }
    bool findWord(vector<vector<char>> &board,string &word,int idx,int i,int j,vector<vector<int>> &visited){
        int n = board.size();
        int m = board[0].size();
        if(idx==word.size()) return true;
        if(i<0 || i>=n || j<0 || j>=m) return false;
        int ch = word[idx];
        if(ch!=board[i][j] || visited[i][j]){
            return false;
        }
        visited[i][j] = 1;
        bool found = 
        findWord(board,word,idx+1,i+1,j,visited) ||
        findWord(board,word,idx+1,i-1,j,visited) ||
        findWord(board,word,idx+1,i,j+1,visited) ||
        findWord(board,word,idx+1,i,j-1,visited);

        visited[i][j] = 0;
        return found;
    }
};
