class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[n-1];
        int x = min(first.size(), last.size());
        for(int i = 0; i < x; i++){
            if(first[i] == last[i]) ans += first[i];
            else return ans;
        }
        return ans;
    }
};