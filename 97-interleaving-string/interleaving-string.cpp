class Solution {
public:

    bool rec(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp){
        int n = s1.size();
        int m = s2.size();
        int N = s3.size();
        int k = i + j;

        if(i == n && j == m && k == N) return true;
        if(k >= N) return false;
        if(dp[i][j] != -1) return dp[i][j];

        bool check = false;
        if(i < n && s1[i] == s3[k]){
            check = rec(s1, s2, s3, i+1, j, dp);
        }
        if(j < m && s2[j] == s3[k]){
            check = check || rec(s1, s2, s3, i, j+1, dp);
        }
        return dp[i][j] = check;
    } 

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int N = s3.size();
        if(n+m != N) return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return rec(s1, s2, s3, 0, 0, dp);
    }
};