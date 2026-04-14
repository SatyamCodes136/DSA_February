class Solution {
public:
    int func(vector<int> &cost, vector<int> &dp, int i){
        int n = cost.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int oneStep = func(cost, dp, i+1);
        int twoStep = func(cost, dp, i+2);
        return dp[i] = cost[i] + min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(func(cost, dp, 0), func(cost, dp, 1));
    }
};