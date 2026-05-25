class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &e: prerequisites){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
            
        }
        
        queue<int>q;
        vector<int>ans;
        vector<int>indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        if(ans.size() < numCourses)
            return {};
        else
            return ans;
    
    }
};
