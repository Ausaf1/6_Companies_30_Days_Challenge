class Solution {
    int count(int n,int prefix){
        if(prefix > n) return 0;
        if(prefix == n) return 1;
        int64_t minPrefix = prefix,mxPrefix = prefix, cnt = 1;
        while(1){
            minPrefix *= 10;
            mxPrefix = 10*mxPrefix + 9;
            if(n < minPrefix) break;
            if(n >= minPrefix && n <= mxPrefix){
                cnt += n - minPrefix + 1;
                break;
            }
            else{
                cnt += mxPrefix - minPrefix + 1;
            }
        }
        return cnt;
    }
public:
    int findKthNumber(int n, int k, int prefix = 0) {
        for(int i = (prefix == 0) ? 1 : 0; i <= 9;i++){
            if(k == 0) return prefix;
            int np = count(n,prefix * 10 + i);
            if(np >= k) return findKthNumber(n,k-1,prefix*10 + i);
            else k -= np;
        }
        return prefix;
    }
};