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
private:
    ListNode* merge(ListNode* p, ListNode* q){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(p != nullptr && q != nullptr){
            if(p->val <= q->val){
                temp->next = p;
                p = p->next;
            }
            else{
                temp->next = q;
                q = q->next;
            }
            
            temp = temp->next;
        }

        if(p != nullptr){
            temp->next = p;
        }
        else{
            temp->next = q;
        }
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        auto node = lists[0];
        for(int i=1; i<lists.size(); i++){
             node = merge(lists[i], node);
            
        }
        return node;
    }
};
