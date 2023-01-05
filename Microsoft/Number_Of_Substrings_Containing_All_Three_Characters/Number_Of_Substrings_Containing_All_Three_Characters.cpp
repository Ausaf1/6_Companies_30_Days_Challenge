class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0,j = 0;
        int n = s.length();
        vector<int> v(3,0);
        for(int i = 0;i < n;i++){
            v[s[i] - 'a']++;
            while(v[0] && v[1] && v[2]){
                count += n - i;
                v[s[j] - 'a']--;
                j++;
            }
        }
        return count;
    }
};