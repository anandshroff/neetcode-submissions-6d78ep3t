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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode *curr, *n;
        curr = n = head;

        while(curr){
            n = n->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *L, *R;
        L = R = head;
        ListNode* prev, *n;
         prev = nullptr;
        while(--left){
            prev = L;
            L = L->next;
        }

        while(--right){
            R = R->next;
        }
        n = R->next;
        R->next = nullptr;
        
        if(prev){
            prev->next = reverse(L);
        }
        else{
            head = reverse(L);
        }
        L->next = n;

        return head; 
    }
};