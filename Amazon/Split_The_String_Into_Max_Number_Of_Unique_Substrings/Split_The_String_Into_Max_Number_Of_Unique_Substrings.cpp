class Solution {
public:
    int res = 1;
    void helper(string &s,int idx,vector<string> &temp,set<string> &st){
        if(idx == s.length()){
            int len = temp.size();
            res = max(res,len);
            return;
        }
        string str = "";
        for(int i = idx;i < s.length();i++){
            str += s[i];
            if(!st.count(str)){
                temp.push_back(str);
                st.insert(str);
                helper(s,i+1,temp,st);
                st.erase(str);
                temp.pop_back();
            }
        }
    }
    int maxUniqueSplit(string s) {
        vector<string> temp;
        set<string> st;
        helper(s,0,temp,st);
        return res;
    }
};