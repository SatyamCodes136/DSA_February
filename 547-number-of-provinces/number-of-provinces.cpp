class Solution {
public:

    // dfs function 
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        //creating adj list
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};