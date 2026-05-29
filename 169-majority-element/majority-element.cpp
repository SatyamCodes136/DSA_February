class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mxFreq = 0;
        int res = 0;
        for(int i : nums){
            mp[i]++;
        }
        for(auto x: mp){
            if(x.second > mxFreq){
                mxFreq = x.second;
                res = x.first;
            }
        }
    return res;
    }
};