class Solution {
public:
    int target = 0;
    vector<int> res;
    void helper(int n,int numArrows,vector<int>& aliceArrows,int sum,vector<int> &ans){
        if(n == -1 || numArrows <= 0){
            if(sum > target){
                target = sum;
                if(numArrows > 0) ans[0] += numArrows;
                res = ans;
            }
            return;
        }
        int required = aliceArrows[n] + 1;
        if(required <= numArrows){
            ans[n] = required;
            helper(n-1,numArrows - required,aliceArrows,sum + n,ans);
            ans[n] = 0;
        }
        helper(n-1,numArrows,aliceArrows,sum,ans);
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans(12,0);
        helper(11,numArrows,aliceArrows,0,ans);
        return res;
    }
};