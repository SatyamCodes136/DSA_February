class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char a: t){
            mp[a]++;
        }
        int l = 0, r = 0;
        int cnt = t.size();
        int minLen = INT_MAX;
        int start = 0;
        while(r < s.size()){
            if(mp[s[r]] > 0) cnt--;
            mp[s[r]]--;
            r++;
            while(cnt == 0){
                if(r-l < minLen){
                    minLen = r-l;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt++;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};