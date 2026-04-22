class Solution {
public:

    int rec(vector<int> &coins, vector<vector<int>> &dp, int amount, int i){
        int n = coins.size();
        if(i == n){
            if(amount == 0) return 0;
            else return INT_MAX;
        }
        if(dp[amount][i] != -1) return dp[amount][i];
        int notTake = rec(coins, dp, amount, i+1);
        int take = INT_MAX;
        if(coins[i] <= amount){
            int res = rec(coins, dp, amount-coins[i], i);
            if(res != INT_MAX) take = 1 + res;
        }
        return dp[amount][i] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n, -1));
        int x = rec(coins, dp, amount, 0);
        return x == INT_MAX ? -1 : x;
    }
};