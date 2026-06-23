class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cmax = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            cmax = max(nums[i], nums[i]+cmax);
            maxi = max(maxi, cmax);
        }
        return maxi;
    }
};