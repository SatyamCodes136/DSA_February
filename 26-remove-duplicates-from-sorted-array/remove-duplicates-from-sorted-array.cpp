class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 0) return 0;
        int k = 1; // first ele is always unique
        for(int i = 0; i < n; i++){
            if(nums[i] != nums[k-1]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};