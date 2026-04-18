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
        if(n == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> dp1(n, -1);
        vector<int> nums2(nums.begin()+1, nums.end());
        vector<int> dp2(n, -1);
        int case1 = rec(nums1, dp1, 0);
        int case2 = rec(nums2, dp2, 0);
        return max(case1, case2);
    }
};