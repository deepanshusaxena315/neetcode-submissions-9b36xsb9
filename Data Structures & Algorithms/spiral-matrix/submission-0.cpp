class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;

        while(top<=bottom && left<=right){

            //left-right
            for(int j=left;j<=right;j++){
                ans.push_back(matrix[top][j]);
            }
            top++;

            //top-bottom
            for(int j=top;j<=bottom;j++){
                ans.push_back(matrix[j][right]);
            }
            right--;

            //right-left
            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;

            }

            //bottom-top
            if(left<=right){
                for(int j=bottom;j>=top;j--){
                    ans.push_back(matrix[j][left]);
                }
                left++;
            }

        }
        return ans;
    }
};
