class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int temp = 256;
        for(int i = 1;i <= 3;i++){
            for(int j = 1;j <= 3;j++){
                for(int k = 1;k <= 3;k++){
                    for(int m = 1;m <= 3;m++){
                        if(i + j + k + m == s.length()){
                            string s1=to_string(stoi(s.substr(0,i)));
                            string s2=to_string(stoi(s.substr(i,j)));
                            string s3=to_string(stoi(s.substr(i+j,k)));
                            string s4=to_string(stoi(s.substr(i+j+k,m)));
                            if(stoi(s1) < temp && stoi(s2) < temp && stoi(s3) < temp && stoi(s4) < temp){
                                string t = s1 + "." + s2 + "." + s3 + "." + s4;
                                if(t.length() == s.length() + 3) res.push_back(t);
                            }    
                        }
                    }
                }
            }
        }
        return res;
    }
};