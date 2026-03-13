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
        int l = 0;
        ListNode* temp = head;
        while(temp != NULL){
            l++;
            temp = temp->next;
        }
        if(n == l){
            head = head->next;
            return head;
        }
        int m = (l-n); //index to be deleted
        temp = head;
        for(int i = 1; i < m; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};