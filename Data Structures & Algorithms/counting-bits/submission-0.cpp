class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            int ones = setBits(i);
            res.push_back(ones);
        }
        return res;
    }

    int setBits(int num){
        int ans = 0;
        while(num){
            num = num&(num-1);
            ans++;
        }
        return ans;
    }
};
