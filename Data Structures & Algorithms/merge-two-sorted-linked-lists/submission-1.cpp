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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        if(!list1 && list2) return list2;
        if(list1 && !list2) return list1;

        ListNode* node;
        if(list1->val < list2->val){
            node = new ListNode(list1->val);
            node->next = mergeTwoLists(list1->next, list2);
        }
        else{
            node = new ListNode(list2->val);
            node->next = mergeTwoLists(list1, list2->next);
        }
        return node;
    }
};
