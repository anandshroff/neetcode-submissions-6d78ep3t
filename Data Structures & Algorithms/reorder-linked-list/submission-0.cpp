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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow;
        ListNode* fast;
        slow = fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* n = slow;
        ListNode* prev = NULL;

        while(n)
        {
            n = n->next;
            slow->next = prev;
            prev = slow;
            slow = n;
        }
        ListNode* curr = head;
        ListNode* p1 = prev->next;
        n = head->next;

        while(p1 != nullptr)
        {
            curr->next = prev;
            prev->next = n;
            prev = p1;
            curr = n;
            n = n->next;
            p1 = p1->next;
        }
    }
};
