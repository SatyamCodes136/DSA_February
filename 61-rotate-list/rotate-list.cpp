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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* tail = NULL;
        if(head == NULL || head->next == NULL) return head;
        int n = 0;
        while(temp != NULL){
            if(temp->next == NULL) tail = temp;
            n++;
            temp = temp->next;
        }
        temp = head;

        if(k == 0) return head;
        k = k % n;

        int i = 1;
        while(i < n-k){
            temp = temp->next;
            i++;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};