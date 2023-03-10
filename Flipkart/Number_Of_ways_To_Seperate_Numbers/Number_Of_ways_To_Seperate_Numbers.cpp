class Solution {
public:
    int numberOfCombinations(string num) {
        if(num[0]=='0')
            return 0;
        
        int n = num.size();
        int MOD = 1000000007;
        vector<vector<int>> dp(n, vector<int>((n/2)+1, 0));
        dp[n-1][0]=1;
        
        for(int i = n-2; i>=0; --i){
            int subtotal = 0;
            
            if((n-i)%2==0 && num.compare(i, (n-i)/2, num, i+(n-i)/2, (n-i)/2) <= 0){
                ++subtotal;
                dp[i][(n-i)/2]=1;
            }
            
            if(num[i]=='0')
                continue;
            
            for(int j = (n-i)/2 - (n-i+1)%2; j > 0; --j){
                if(num[i+j]!='0'){
                    if(j > (n-i)/3){
                        subtotal = (subtotal+1)%MOD;
                        dp[i][j] = subtotal;
                    }
                    else if(num.compare(i, j, num, i+j, j) <= 0){
                        subtotal = (subtotal + 1 + dp[i+j][j])%MOD;
                        dp[i][j] = subtotal;
                    }
                    else{
                        if(j+1 < (n/2)+1)
                            subtotal = (subtotal + 1 + dp[i+j][j+1])%MOD;
                        else
                            subtotal = (subtotal+1)%MOD;
                        dp[i][j]=subtotal;
                    }
                }
                else
                    dp[i][j]=subtotal;
                
            }
            dp[i][0]=(subtotal+1)%MOD;
        }
        
        return dp[0][0];
    }
};