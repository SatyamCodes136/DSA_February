class Solution {
public:

    void dfs(int sr, int sc, int color, int ic, vector<vector<int>> &ans, vector<int> &delrow, vector<int> &delcol, vector<vector<int>>& image){
        int n = image.size();
        int m = image[0].size();
        ans[sr][sc] = color;
        for(int i = 0; i < 4; i++){
            int nrow = sr+delrow[i];
            int ncol = sc+delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == ic && ans[nrow][ncol] != color){
                dfs(nrow, ncol, color, ic, ans, delrow, delcol, image);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ic = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        dfs(sr,sc,color,ic,ans,delrow, delcol, image);
        return ans;
    }
};