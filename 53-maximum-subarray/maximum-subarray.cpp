class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0]; //overall max
        int cmax = nums[0]; //curr max
        for(int i= 1; i < nums.size(); i++){
            cmax = max(nums[i], nums[i]+cmax);
            maxi = max(maxi, cmax);
        }
        return maxi;
    }
};