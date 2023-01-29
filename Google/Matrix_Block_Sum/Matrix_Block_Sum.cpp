class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> prefix(r+1,vector<int>(c+1,0));
        vector<vector<int>> res(r,vector<int>(c));
        for(int i = 1;i <= r;i++){
            for(int j = 1;j <= c;j++){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + mat[i-1][j-1] - prefix[i-1]                                [j-1];
            }
        }
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                int mini = max(0,i-k);
                int minj = max(0,j-k);
                int maxi = min(i+k,r-1);
                int maxj = min(j+k,c-1);
                res[i][j] = prefix[maxi + 1][maxj + 1] + prefix[mini][minj] 
                    - prefix[maxi + 1][minj] - prefix[mini][maxj + 1];
            }
        }
        return res;
    }
};