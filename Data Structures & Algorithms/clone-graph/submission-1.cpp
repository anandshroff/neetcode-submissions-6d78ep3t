/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*>mp;
    Node* bfs(Node* node)
    {
        queue<Node*>q;
        q.push(node);
        mp[node] = new Node(node->val);
        while(!q.empty())
        {
            Node* tnode = q.front();
            q.pop();
            
            for(Node* nei: tnode->neighbors)
            {
                if(mp.find(nei) == mp.end()){
                    mp[nei] = new Node(nei->val);
                    q.push(nei);
                }
                mp[tnode]->neighbors.push_back(mp[nei]);
            }
        }   
        return mp[node];
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        return bfs(node);
    }
};
