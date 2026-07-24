class Solution {
public:

    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, int &nd, int &ed){
        vis[node] = 1;
        nd++;
        for(auto it: adj[node]){
            ed++;
            if(!vis[it]){
                dfs(it, vis, adj, nd, ed);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                int nd = 0;
                int ed = 0;
                dfs(i, vis, adj, nd, ed);
                ed /= 2;
                if(ed == (nd *(nd-1))/2) ans++;
            }
        }
        return ans;
    }
};