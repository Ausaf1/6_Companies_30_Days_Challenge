class Solution {
public:
    int magicalString(int n) {
        if(n <= 3) return 1;
        string s = "122";
        int ans = 1,i = 2;
        char pre = '2';
        while(s.size() < n){
            int count = s[i++] - '0';
            if(pre == '1'){
                while(count-- && s.size() < n) s += '2';
            }
            else{
                while(count-- && s.size() < n) s += '1',ans++;
            }
            pre = pre =='1' ? '2' : '1';
        }
        return ans;
    }
};