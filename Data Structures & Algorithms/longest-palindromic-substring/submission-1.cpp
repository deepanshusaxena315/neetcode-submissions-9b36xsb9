class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(((j-i+1)>maxi) && isPalindrome(i,j,s)){
                    maxi = j-i;
                    ans = s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
    bool isPalindrome(int i,int j,string &s){
        while(i<j && s[i]==s[j]){
            i++;
            j--;
        }
        if(i<j) return false;
        return true;
    }
};
