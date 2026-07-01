class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxi = 0;
        int n = s.size();
        map<char,int> mp;
        for(int i = 0; i < n; i++){
            char a = s[i];
            if(mp.find(a) != mp.end()){
                left = max(left, mp[a]+1);
            }
            mp[a] = i;
            maxi = max(maxi, mp[a]-left+1);
        }
        return maxi;
    }
};