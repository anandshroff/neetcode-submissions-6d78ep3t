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
        ListNode* curr, *n;
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
        ListNode *prev = nullptr, *rev = nullptr;
        ListNode *revend = nullptr, *revnext = nullptr;
        ListNode* curr = head;
        int i=1;
        while(curr && i<=right){
            if(i<left){
                prev = curr;
            }
            if(i == left){
                rev = curr;
            }
            if(i == right){
                revend = curr;
                revnext = curr->next;
            }
            curr = curr->next;
            i++;
        }
        revend->next = nullptr;
        if(prev){
            prev->next = reverse(rev);
        }
        else{
            head = reverse(rev);
        }

        rev->next = revnext;
        return head;
    }
};