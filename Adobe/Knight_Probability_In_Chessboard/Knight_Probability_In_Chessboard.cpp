class Solution {
    double dp[26][26][101];
    int dx[8] = {2,-2,-2,2,1,-1,-1,1};
    int dy[8] = {1,-1,1,-1,2,-2,2,-2};
public:
    double helper(int i,int j,int n,int k){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(k == 0) return 1;
        if(dp[i][j][k]) return dp[i][j][k];
        double s = 0;
        for(int x = 0;x < 8;x++) s += helper(i + dx[x],j + dy[x],n,k-1);
        return dp[i][j][k] = s/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        return helper(row,column,n,k);
    }
};