class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto a: mp){
            if(a.second > 1) return true;
        }
        return false;
    }
};