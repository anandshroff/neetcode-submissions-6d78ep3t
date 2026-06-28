/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int, ListNode*>>>pq;

        //push all the first node in the list (head)
        for(auto nodes:lists){
            if(nodes)
            pq.push({nodes->val, nodes});
        }
        // create a dummy node for ans
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        //iterate until the pq becomes empty
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            //appending the smallest val node in ans
            temp->next = node.second;
            //push smallest node's next if exists into pq
            if(node.second->next){
                pq.push({node.second->next->val, node.second->next});
            }
            //move the temp pointer
            temp = temp->next;
        }
        return dummy->next;
    }
};
