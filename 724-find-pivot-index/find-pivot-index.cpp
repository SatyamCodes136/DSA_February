class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int x: nums) total += x;
        int left = 0;
        int right = 0;
        for(int i = 0; i < n; i++){
            right = total-left-nums[i];
            if(left == right) return i;
            left += nums[i];
        }
        return -1;
    }
};