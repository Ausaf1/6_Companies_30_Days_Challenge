class Solution {
public:
    int helper(vector<vector<int>>& dungeon,int i,int j,int m, int n,vector<vector<int>> &dp){
        if(i >= m + 1 || j >= n+1) return 1e9;
        if(i == m && j == n) return dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = helper(dungeon,i+1,j,m,n,dp);
        int right = helper(dungeon,i,j+1,m,n,dp);
        int ans = min(down,right) - dungeon[i][j];
        return dp[i][j] = ans > 0 ? ans : 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(),n = dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return helper(dungeon,0,0,m-1,n-1,dp);
    }
};