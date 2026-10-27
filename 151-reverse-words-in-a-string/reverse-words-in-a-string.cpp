class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ' ') continue;
            string temp = "";
            while(i >= 0 && s[i] != ' '){
                temp += s[i];
                i--;
            }
            reverse(temp.begin(), temp.end());
            if(!ans.empty()) ans += " ";
            ans += temp;
        }
        return ans;
    }
};