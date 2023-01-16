class Solution {
public:
map<vector<int>,int> mp;
    bool check(vector<int> &need){
        for(int i = 0;i < need.size();i++){
            if(need[i] < 0) return false;
        }
        return true;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(mp[needs] > 0) return mp[needs];
        int mn = 0;
        for(int i = 0;i < needs.size();i++){
            mn += needs[i]*price[i];
        }
        for(auto s : special){
            vector<int> need = needs;
            for(int i = 0;i < needs.size();i++){
                need[i] -= s[i];
            }
            if(check(need)) mn = min(mn,s[s.size() - 1] + shoppingOffers(price,special,need));
        }
        return mp[needs] = mn;
    }
};