class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long mn = INT_MAX,count = 0,sum = 0;
        for(auto m : matrix){
            for(auto i : m){
                if(i < 0) count++;
                mn = min(mn,(long long)abs(i));
                sum += abs(i);
            }
        }
        return (count & 1) ? sum - 2*mn : sum;
    }
};