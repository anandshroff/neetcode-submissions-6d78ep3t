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
        ListNode* prev, *nNode, *curr;
        curr = nNode = head;
        prev = nullptr;

        while(curr){
            nNode = nNode->next;
            curr->next = prev;
            prev = curr;
            curr = nNode;
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
         ListNode* pivot = slow->next;
         slow->next = nullptr;

         ListNode* newhead = reverse(pivot);

         ListNode *h1, *n1, *n2;
         h1 = head;
         n1 = h1->next;
         n2 = newhead;

         while(n1 && n2){
            h1->next = n2;
            h1 = h1->next;
            n2 = n2->next;
            h1->next = n1;
            n1 = n1->next;
            h1 = h1->next;
         }
    }
};
