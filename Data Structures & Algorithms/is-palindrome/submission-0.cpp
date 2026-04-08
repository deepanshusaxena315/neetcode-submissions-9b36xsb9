class Solution {
public:
    bool isPalindrome(string s) {
        string modified = "";
        for(auto &ch: s){
            if((ch<='z' && ch>='a') || (ch<='9' && ch>='0')) modified+= ch;
            else if(ch<='Z' && ch>='A'){
                modified+= tolower(ch);
            }
        }
        int n = modified.size();
        for(int i=0;i<=n/2-1;i++){
            if(modified[i]!=modified[n-i-1]) return false;
        }
        return true;
    }
};
