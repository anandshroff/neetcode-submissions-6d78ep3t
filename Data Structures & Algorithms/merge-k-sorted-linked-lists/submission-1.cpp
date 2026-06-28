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
        //lambda function for comparator
        auto compare = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        // use decltype(cmp) and pq(cmp) in priority queue for  custom comparator
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare) > pq(compare);

        //push all the first node in the list (head)
        for(auto nodes:lists){
            pq.push(nodes);
        }
        // create a dummy node for ans
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        //iterate until the pq becomes empty
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            //appending the smallest val node in ans
            temp->next = node;
            //push smallest node's next if exists into pq
            if(node->next){
                pq.push(node->next);
            }
            //move the temp pointer
            temp = temp->next;
        }
        return dummy->next;
    }
};
