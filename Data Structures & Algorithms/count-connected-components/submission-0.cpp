class Solution {
private:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj){
        vis[node] = 1;

        for(auto v:adj[node]){
            if(!vis[v]){
                dfs(v, vis, adj);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>vis(n);
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components = 0;
        for(int i=0; i<n;i++){
            if(!vis[i]){
                components++;
                dfs(i, vis, adj);
            }
        }
        return components;
    }
};
