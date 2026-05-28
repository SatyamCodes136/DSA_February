class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i = 0; i < n; i++){
            int comp = target - nums[i]; // complement
            if(m.find(comp) != m.end()) return {m[comp], i};
            m[nums[i]] = i;
        }
        return {};
    }
};