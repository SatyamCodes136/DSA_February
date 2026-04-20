class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n <= 1) return n;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int sum = 0;

        // check for len 1
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            sum++;
        }

        // check for len 2
        for(int i = 0; i <= n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                sum++;
            }
        }

        // check for len 3
        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n-len; i++){
                int j = i+len-1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    sum++;
                }
            }
        }

        return sum;
    }
};