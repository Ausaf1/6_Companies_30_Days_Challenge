class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> count(n);
        int nz = 0,res = 0;
        for(int l = 0,r = 0;r < n;r++){
            if(!count[fruits[r]]++) nz++;
            while(nz > 2){
                if(!--count[fruits[l++]]) nz--;
            }
            res = max(res,r - l + 1);
        }
        return res;
    }
};