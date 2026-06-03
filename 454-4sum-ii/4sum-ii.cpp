class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int cnt = 0;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int sum = nums1[i]+nums2[j];
                mp1[sum]++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int sum = nums3[i]+nums4[j];
                mp2[sum]++;
            }
        }
        for(auto a : mp1){
            int sum1 = a.first;
            int freq1 = a.second;
            int target = -sum1;
            if(mp2.find(target) != mp2.end()) cnt += freq1 * mp2[target];
        }
        return cnt;
    }    
};