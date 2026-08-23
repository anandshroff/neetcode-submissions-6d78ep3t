class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>out(n+1,0);
        vector<int>in(n+1,0);

        for(auto node:trust){
            int u = node[0];
            int v = node[1];
            out[u]++;
            in[v]++;
        }

        for(int i=0;i<=n;i++){
            if(in[i] == n-1 && out[i] == 0)
                return i;
        }

        return -1;
    }
};