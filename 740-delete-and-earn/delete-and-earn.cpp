class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for(int x : nums) maxVal = max(maxVal, x);

        vector<int> sum(maxVal + 1, 0);
        for(int x : nums) {
            sum[x] += x;
        }

        // House Robber DP
        int prev2 = 0; // dp[i-2]
        int prev1 = sum[0]; // dp[i-1]

        for(int i = 1; i <= maxVal; i++) {
            int take = sum[i] + prev2;
            int notTake = prev1;

            int curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};