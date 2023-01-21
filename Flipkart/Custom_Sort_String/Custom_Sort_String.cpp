class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        for(auto c : s) mp[c]++;
        string res;
        for(auto j : order){
            int n = mp[j];
            for(int i = 0;i < n;i++){
                res += j;
                mp[j]--;
            }
        }
        for(auto k : mp){
            if(k.second != 0){
                for(int i = 0;i < k.second;i++){
                    res += k.first;
                    mp[k.first]--;
                }
            }
        }
        return res;
    }
};