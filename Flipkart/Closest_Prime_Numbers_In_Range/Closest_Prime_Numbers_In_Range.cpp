class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> seive(1e6 + 1,true);
        seive[0] = seive[1] = false;
        for(int i = 2;i*i <= 1e6;i++){
            for(int j = 2;i*j <= 1e6;j++){
                seive[i*j] = false;
            }
        }
        
        vector<int> res,temp;
        int diff = INT_MAX;
        for(int i = left;i <= right;i++){
            if(seive[i]){
                temp.push_back(i);
                if(temp.size() == 2){
                    if(temp[1] - temp[0] < diff){
                        diff = temp[1] - temp[0];
                        res = temp;
                    }
                    temp.clear();
                    temp.push_back(i);
                }
            }
        }
        if(res.size() == 0) return {-1,-1};
        return res;
    }
};