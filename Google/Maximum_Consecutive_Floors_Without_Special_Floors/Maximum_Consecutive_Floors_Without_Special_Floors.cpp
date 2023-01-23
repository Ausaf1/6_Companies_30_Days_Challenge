class Solution {
public:
    #define ll long long
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        sort(special.begin(),special.end());
        int a = 0,ans = 0;
        if(bottom < special[0])
            a = special[0] - bottom;
        ans = max(a,ans);
        if(top > special[n-1])
            a = top - special[n-1];
        ans = max(ans,a);
        for(int i = 0;i < n-1;i++){
            ans = max(ans,special[i+1] - special[i]-1);
        }
        return ans;
    }
};