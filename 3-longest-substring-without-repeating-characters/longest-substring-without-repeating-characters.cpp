class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int maxi = 0;
        map<char,int> mp; // stores index of a char
        for(int i = 0; i < s.size(); i++){
            char a = s[i];
            if(mp.find(a) != mp.end()){
                start = max(start, mp[a]+1);
            }
            mp[a] = i;
            maxi = max(maxi, i-start+1);
        }
        return maxi;
    }
};