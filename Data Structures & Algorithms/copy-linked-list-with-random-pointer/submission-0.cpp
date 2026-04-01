/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mpp;
        mpp[NULL] = NULL;
        Node* curr = head;

        while(curr != NULL){
            Node* newNode = new Node(curr->val);
            mpp[curr] = newNode;
            curr = curr->next;
        }
        curr = head;
        while(curr != NULL){
            Node* newNode = mpp[curr];
            newNode->next = mpp[curr->next];
            newNode->random = mpp[curr->random];
            curr = curr->next;
        }
        return mpp[head];
    }
};
