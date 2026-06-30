class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int currm = 0;
        for(int i = 0; i< nums.size(); i++){
            currm = max(nums[i], nums[i]+currm);
            maxi = max(maxi, currm);
        }
        return maxi;
    }
};