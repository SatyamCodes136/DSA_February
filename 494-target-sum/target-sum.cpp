class Solution {
public:

    int rec(int i, int sum, vector<int> & nums, int target, vector<vector<int>> &dp, int total){
        int n = nums.size();
        if(i == n) return (sum == target) ? 1 : 0;
        if(dp[i][sum+total] != -1) return dp[i][sum+total];
        int positive = rec(i+1, sum+nums[i], nums, target, dp, total);
        int negative = rec(i+1, sum-nums[i], nums, target, dp, total);
        return dp[i][sum+total] = positive + negative;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++){
            total += nums[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(total*2+1, -1));
        return rec(0, 0, nums, target, dp, total);
    }
};