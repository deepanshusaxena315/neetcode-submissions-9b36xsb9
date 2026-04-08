class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right =s.size()-1;
        if(s.size()<=1) return true;
        while(left<right){
            while(!isalnum(s[left])){
                left++;
            }
            while(!isalnum(s[right])) right--;
            if(left<right){
                if(tolower(s[left]) == tolower(s[right])){
                    left++;
                    right--;
                } 
                else return false;
            }
        }
        return true;
    }
};
