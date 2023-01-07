class Solution {
public:
    int dist(vector<int> &p1,vector<int> &p2){
        return (p2[0] - p1[0])*(p2[0] - p1[0]) + (p2[1] - p1[1])*(p2[1] - p1[1]);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(),ans = 0;
        for(int i = 0;i < n;i++){
            map<int,int> mp;
            for(int j = 0;j < n;j++){
               if(i == j) continue;
               int dis = dist(points[i],points[j]);
               if(mp.find(dis) != mp.end()) ans += mp[dis]*2;
               mp[dis]++;
            }
        }
        return ans;
    }
};