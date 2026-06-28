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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode *np = head;
        
        while(np){
            np = np->next;
            curr->next = prev;
            prev = curr;
            curr = np;
        }
        
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        int x = k;
        ListNode* t = head;
        ListNode* l = head;
        ListNode *r = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* node = dummy;
        while(l){
            while(x-1 && r->next){
                r = r->next;
                x--;
            }
            
            if(x>1) break;

            t = r->next;
            r->next = nullptr;
            node->next = reverse(l);
            node = l;
            l->next = t;
            l = t;
            r = t;
            x = k;
            
        }
        return dummy->next;
    }
};
