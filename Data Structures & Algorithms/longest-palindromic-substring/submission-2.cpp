class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        int maxi = 1;
        int start = 0;
        //i as center
        for(int i=0;i<n;i++){
            int r= i;
            int l = i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxi<r-l+1){
                    maxi = r-l+1;
                    start = l;
                }
                r++;
                l--;
            }

        }
        for(int i=0;i<n-1;i++){
            int r= i+1;
            int l =i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxi<r-l+1){
                    maxi = r-l+1;
                    start = l;
                }
                r++;
                l--;
            }
        }
        return s.substr(start,maxi);

    }
    // bool isPalindrome(int i,int j,string &s){
    //     while(i<j && s[i]==s[j]){
    //         i++;
    //         j--;
    //     }
    //     if(i<j) return false;
    //     return true;
    // }
};
