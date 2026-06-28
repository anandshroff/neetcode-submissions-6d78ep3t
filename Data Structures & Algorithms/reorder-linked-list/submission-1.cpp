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
        ListNode* n = head;
        ListNode* curr = head;

        while(n){
            n = n->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nHead = slow->next;
        slow->next = nullptr;
        
        
        nHead = reverse(nHead);

        ListNode* n1 = head;
        ListNode* n2 = nHead;
        ListNode* curr = head;

        while(n2){
            n1 = n1->next;
            n2 = n2->next;
            curr->next = nHead;
            nHead->next = n1;
            curr = n1;
            nHead = n2;
        }

    }
};
