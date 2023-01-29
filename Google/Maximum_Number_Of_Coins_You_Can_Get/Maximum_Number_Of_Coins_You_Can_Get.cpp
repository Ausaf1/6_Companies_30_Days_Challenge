class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int i = 1,j = piles.size() - 1,res = 0;
        sort(piles.begin(),piles.end(),greater<int>());
        while(i < j){
            res += piles[i];
            i+=2;
            j--;
        }
        return res;
    }
};