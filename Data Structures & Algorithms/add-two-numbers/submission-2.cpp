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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* c1;
        ListNode* c2;
        c1 = l1;
        c2 = l2;

        ListNode* newNode = new ListNode();
        ListNode* n1 = newNode;
        int temp;
        int carry=0;
        temp = c1->val + c2->val + carry;
        carry = temp/10;
        n1->val = temp%10;        

        

        while(c1->next || c2->next){
            ListNode* Node = new ListNode();
            int val1, val2;
            n1->next = Node;
            n1 = n1->next;
            
            if(c1->next && !c2->next)
            {
                c1 = c1->next;
                val1 = c1->val;
                val2 = 0;
            }
            else if(!c1->next && c2->next)
            {
                c2 = c2->next;
                val1 = 0;
                val2 = c2->val;
                
            }
            else{
                c1 = c1->next;
                c2 = c2->next;
                val1 = c1->val;
                val2 = c2->val;
            }
            
            
            temp = val1 + val2 + carry;
            carry = temp/10;
            n1->val = temp%10;

        }

        
        if(carry>=1)
        {
            ListNode* Node = new ListNode();
            n1->next = Node;
            Node->val = carry;
        }            
        return newNode;
    }
};
