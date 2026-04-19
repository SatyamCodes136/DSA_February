class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        int e=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,i+nums[i]);
            if(i==e){
                e=maxi;
            }
        }
        if(e>=n-1) return true;
        return false;
    }
};