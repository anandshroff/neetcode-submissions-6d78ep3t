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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr;
        ListNode* prev = nullptr;
        curr = head;
        int count = 0;
        
        while(curr){
            curr = curr->next;
            count++;
        }

        count = count - n;
        curr = head;

        if (count == 0){
            head = head->next;
            delete curr;
            return head;
        }


        while(count){
            if(count == 1)
            prev = curr;
            curr = curr->next;
            count--;
        }

        prev->next = curr->next;
        delete curr;

        return head;
        
    }
};
