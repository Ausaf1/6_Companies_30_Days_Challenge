class Solution {
private:
    double dist(vector<int> &p1, vector<int> &p2){
        return (((p2[0] - p1[0]) * (p2[0] - p1[0])) + ((p2[1] - p1[1]) * (p2[1] - p1[1])));
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1,p2,p3,p4};
        set<double> st;
        for(int i = 0;i < 4;i++){
            for(int j = i+1;j < 4;j++){
                double val = dist(points[i],points[j]);
                if(val == 0) return false;
                st.insert(val);
            }
        }
        return st.size() == 2;
    }
};