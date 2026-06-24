class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        int x = min(first.size(), last.size());
        for(int i = 0; i < x; i++){
            if(first[i] == last[i]) s += first[i];
            else return s;
        }
        return s;
    }
};