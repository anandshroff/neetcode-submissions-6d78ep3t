class Solution {
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis){
        vis[node] = 1;

        for(auto nbr:adj[node]){
            if(!vis[nbr]){
                dfs(nbr, adj, vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>vis(n);

        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int comp = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                dfs(i, adj, vis);
            }
        }
        return comp;
    }
};
