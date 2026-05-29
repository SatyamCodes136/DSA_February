class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> mp;
        for(char a: s){
            mp[a]++;
        }
        for(char a: t){
            mp[a]--;
            if(mp[a] < 0) return false;
        }
        return true;
    }
};