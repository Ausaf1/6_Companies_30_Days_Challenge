class Solution {
public:
    bool check(int i,int j,int n){
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> v(n,vector<int>(n,1e9));
        v[0][0] = grid[0][0];
        while(!pq.empty()){
            int count = pq.top().first;
            int x = pq.top().second.first,y = pq.top().second.second;
            pq.pop();
            int r[4] = {-1,0,1,0},c[4] = {0,1,0,-1};
            for(int i = 0;i < 4;i++){
                int row = r[i] + x,col = c[i] + y;
                if(check(row,col,n)){
                    if(count < grid[row][col]){
                        v[row][col] = grid[row][col];
                        pq.push({v[row][col],{row,col}});
                    }
                    else if(count < v[row][col]){
                        v[row][col] = count;
                        pq.push({v[row][col],{row,col}});
                    }
                }
            }
        }
        return v[n-1][n-1];
    }
};