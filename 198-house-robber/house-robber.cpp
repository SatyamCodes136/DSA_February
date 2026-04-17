class Solution {
public:

    int rec(vector<int> &nums, vector<int> &dp, int i){
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + rec(nums, dp, i+2); 
        int notTake = rec(nums, dp, i+1);
        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return rec(nums, dp, 0);
    }
};