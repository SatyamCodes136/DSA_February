class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int maxi = 0;
        map<char,int> mp;
        for(int i = 0; i< n; i++){
            char c = s[i];
            if(mp.find(c) != mp.end()){
                left = max(left, mp[c]+1);
            }
            mp[c] = i;
            maxi = max(maxi, i-left+1);
        }
        return maxi;
    }
};