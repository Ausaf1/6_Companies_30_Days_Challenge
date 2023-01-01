class Solution {
public:
    void helper(int k,int n,vector<vector<int>> &combinations,int num, vector<int> &c){
        if(k == 0){
            int sum = 0;
            for(auto a : c) sum += a;
            if(sum == n) combinations.push_back(c);
            return;
        }
        if(num > 9) return;
        c.push_back(num);
        helper(k-1,n,combinations,num+1,c);
        c.pop_back();
        helper(k,n,combinations,num+1,c);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> c;
        helper(k,n,combinations,1,c);
        return combinations;
    }
};