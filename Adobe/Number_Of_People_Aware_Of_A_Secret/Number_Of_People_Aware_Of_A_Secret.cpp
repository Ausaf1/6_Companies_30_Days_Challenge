class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int m = 1e9 + 7;
        long ans = 0;
        vector<long> dp(n+1,0);
        dp[1] = 1;
        long sharing = 0;
        for(int i = 2;i <= n;i++){
            long newPeople = dp[max(0,i-delay)];
            long forgetPeople = dp[max(0,i - forget)];
            sharing += (newPeople - forgetPeople + m) % m;
            dp[i] = sharing; 
        }
        for(int i = n - forget + 1;i <= n;i++) ans = (ans + dp[i]) % m;
        return (int)ans;
    }
};