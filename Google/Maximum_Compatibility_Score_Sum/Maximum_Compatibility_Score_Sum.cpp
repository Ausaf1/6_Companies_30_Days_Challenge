class Solution {
public:
int calculate(int i,int j,vector<vector<int>> &mentors,vector<vector<int>> &students){
    int count = 0;
    for(int k = 0;k < students[0].size();k++){
        if(students[i][k] == mentors[j][k]) count++;
    }
    return count;
}
    int helper(int i,int n,vector<vector<int>> &students,vector<vector<int>> &mentors,vector<bool> &visited){
        if(i == n) return 0;
        int res = 0;
        for(int j = 0;j < n;j++)
        {
            if(!visited[j]){
                visited[j] = 1;
                res = max(res,calculate(i,j,mentors,students) + helper(i + 1,n,students,mentors,visited));
                visited[j] = 0;
            }
        }
        return res;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
       int n = students.size();
       vector<bool> visited(n,0);
       return helper(0,n,students,mentors,visited);
    }
};