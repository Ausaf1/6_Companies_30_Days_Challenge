class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = INT_MIN;
        for(int i = 0;i < n;i++){
            unordered_map<double,int> mp;
            int temp = 0;
            for(int j = 0;j < n;j++){
                if(i == j) continue;
                int x1 = points[i][0],y1 = points[i][1];
                int x2 = points[j][0],y2 = points[j][1];
                double x = x2-x1,y = y2 - y1;
                if(x == 0){
                    mp[INT_MAX]++;
                    temp = max(temp,mp[INT_MAX]);
                    continue;
                }
                double slope = y/x;
                mp[slope]++;
                temp = max(temp,mp[slope]);
            }
            ans = max(ans,temp+1);
        }
        return ans;
    }
};