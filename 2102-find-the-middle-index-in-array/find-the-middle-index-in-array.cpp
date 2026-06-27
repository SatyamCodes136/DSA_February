class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int total = 0;
        for(int x:nums) total += x;
        for(int i = 0; i < n; i++){
            right = total - left -nums[i];
            if(left == right) return i;
            left += nums[i];
        }
        return -1;
    }
};