class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp; //sum,cnt
        int sum = 0;
        int cnt = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int t = sum-k;
            if(mp.find(t) != mp.end()){
                cnt += mp[t];
            }
            mp[sum]++;
        }
        return cnt;
    }
};