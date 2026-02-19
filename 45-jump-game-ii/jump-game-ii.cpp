class Solution {
public:
    int jump(vector<int>& nums) {
        int max_idx = 0;
        int jumps = 0;
        int end = 0;
        for(int i = 0; i < nums.size()-1; i++){
            max_idx = max(max_idx, i + nums[i]);
            if(i == end){
                jumps++;
                end = max_idx;
            }
        }
        return jumps;
    }
};