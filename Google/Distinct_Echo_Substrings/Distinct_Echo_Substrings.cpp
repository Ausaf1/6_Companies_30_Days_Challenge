class Solution {
public:
    bool check(string &s){
        int k = s.size() >> 1;
        for(int i = 0;i < s.size() >> 1;i++){
            if(s[i] != s[k]) return false;
            k++;
        }
        return true;
    }
    int distinctEchoSubstrings(string text) {
        unordered_set<string> st;
        int n = text.size();
        for(int i = 0;i < n;i++){
            string res = "";
            for(int j = i;j < n;j+=2){
                res += text[j];
                if(j + 1 < n) res += text[j + 1];
                else break;
                if(check(res)) st.insert(res);
            }
        }
        return st.size();
    }
};