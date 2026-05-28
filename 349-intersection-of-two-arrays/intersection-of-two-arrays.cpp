class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> ans;
        for(int val: nums2){
            if(s1.find(val) != s1.end()) ans.insert(val);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};