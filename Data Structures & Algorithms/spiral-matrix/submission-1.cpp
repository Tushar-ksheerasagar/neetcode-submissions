class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> ans;
        while(top<=bottom && left <= right){
            for(int i =left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            top++;
            for(int j = top;j<=bottom;j++)
                ans.push_back(matrix[j][right]);
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans.push_back(matrix[bottom][j]);
                bottom--;
            }   
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        } 
        return ans;
    }
};
