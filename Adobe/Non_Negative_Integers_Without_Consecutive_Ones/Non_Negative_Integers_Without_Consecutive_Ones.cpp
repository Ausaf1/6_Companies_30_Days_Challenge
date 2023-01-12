class Solution {
public:
    int findIntegers(int n) {
        vector<int> fib(31);
        fib[0] = 1,fib[1] = 2;
        for(int i = 2;i < 30;i++) fib[i] = fib[i-1] + fib[i-2];
        int ans = 0,cnt = 30,flag = 0;
        while(cnt >= 0){
            if(n & (1 << cnt)){
                ans += fib[cnt];
                if(flag) return ans;
                flag = 1;
            }
            else flag = 0;
            cnt--;
        }
        return ans + 1;
    }
};