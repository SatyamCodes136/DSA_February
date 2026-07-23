class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ts(n+1,0);
        if(n == 1 && trust.size() == 0) return 1;
        for(auto t: trust){
            int a = t[0];
            int b = t[1];
            ts[a]--;
            ts[b]++;
        }
        for(int i = 0; i <= n; i++){
            if(ts[i] == n-1) return i;
        }
        return -1;
    }
};