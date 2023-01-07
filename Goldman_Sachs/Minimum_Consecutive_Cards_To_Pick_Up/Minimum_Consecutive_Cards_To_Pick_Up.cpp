class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map<int,int> m;
        int j = -1,len,ans = INT_MAX;
        for(int i = 0;i < n;i++){
            if(m.find(cards[i]) != m.end()){
                len = i - m[cards[i]] + 1;
                ans = min(ans,len);
            }
            m[cards[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};