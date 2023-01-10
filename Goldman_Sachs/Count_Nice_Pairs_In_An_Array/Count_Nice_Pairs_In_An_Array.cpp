class Solution {
public:
int m = 1e9 + 7;
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0;i < n;i++){
            string s = to_string(nums[i]);
            reverse(s.begin(),s.end());
            int r = stoi(s);
            mp[nums[i] - r]++;
        }
        long res = 0;
        for(auto it : mp){
            long long a = it.second;
            res = (res + (a*(a-1))/2 ) % m;
        }
        return res % m;
    }
};