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
        // step1:- Create a deep copy without random ptr
        Node* dummy = new Node(100);
        Node* tempC = dummy;
        Node* temp = head;
        while(temp){
            Node* a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }
        Node* duplicate = dummy->next;
        //step2:- Alternate connections
        Node* a = head;
        Node* b = duplicate;
        dummy = new Node(10);
        Node* tempD = dummy;
        while(a){
            tempD->next = a;
            a = a->next;
            tempD = tempD->next;
            tempD->next = b;
            b = b->next;
            tempD = tempD->next;
        }
        dummy = dummy->next;
        //step3:- Assign random pointers
        Node* t1 = dummy;
        while(t1){
            Node* t2 =  t1->next;
            if(t1->random) t2->random = t1->random->next;
            t1 = t1->next->next;
        }
        //step4:- Removing the connections
        Node* d1 = new Node(-2);
        Node* d2 = new Node(-1);
        t1 = d1;
        Node* t2 = d2;
        Node* t  = dummy;
        while(t){
            t1->next = t;
            t = t->next;
            t1 = t1->next;
            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1->next = NULL;
        t2->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;
    }
};