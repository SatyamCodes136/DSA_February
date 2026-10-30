class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cmax = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            cmax = max(nums[i], cmax+nums[i]);
            maxi = max(maxi, cmax);
        }
        return maxi;
    }
};