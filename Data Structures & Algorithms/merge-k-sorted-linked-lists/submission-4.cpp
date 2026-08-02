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
    ListNode* merge(ListNode* p, ListNode* q){
        if(!p) return q;
        if(!q) return p;
        ListNode dummy = ListNode(1001, nullptr);
        ListNode* curr = &dummy;

        while(p && q){
            if(p->val <= q->val){
                curr->next = p;
                p = p->next;
            }
            else{
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;
        }

        if(!p) curr->next = q;
        if(!q) curr->next = p;

        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* node = lists[0];
        for(int i=1;i<lists.size();i++){
            
            node = merge(node , lists[i]);
        }
        return node;
    }
};
