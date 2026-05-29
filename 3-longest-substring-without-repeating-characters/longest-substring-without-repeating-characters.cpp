class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_set<int> st;
            for(int j = i; j < s.size(); j++){
                if(st.count(s[j])) break;
                st.insert(s[j]);
                mx = max(mx, j-i+1);
            }
        }
        return mx;
    }
};