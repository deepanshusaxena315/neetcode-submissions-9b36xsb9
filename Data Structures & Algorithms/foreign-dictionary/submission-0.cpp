class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>> adj;
        unordered_map<char,int> indegree;
        for(auto &word: words){
            for(auto &c: word) indegree[c] = 0;
        }

        //building adj list
        for(int i=1;i<words.size();i++){
            string a = words[i-1];
            string b = words[i];
            int len = min(a.size(),b.size());
            int j=0;
            while(j< len && a[j]==b[j]) j++;
            if(j==len && a.size()>b.size()) return "";
            else if(j<len){
                char u = a[j];
                char v = b[j];
                adj[u].push_back(v);
            }
        }
        //calc indegree

        for(auto &e: adj){
            for(auto &n: e.second){
                indegree[n]++;
            }
        }

        queue<char> q;
        string ans  = "";
        for(auto &a: indegree){
            if(a.second==0) q.push(a.first);
        }
        while(!q.empty()){
            char node = q.front();
            q.pop();
            for(auto &n: adj[node]){
                
                    indegree[n]--;
                    if(indegree[n]==0) q.push(n);
                
            }
            ans += node;
        }
        if(ans.size()<adj.size()) return "";
        return ans;
    }
};
