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
    ListNode* partition(ListNode* head, int x) {
        ListNode* Lo = new ListNode(100);
        ListNode* Hi = new ListNode(101);
        ListNode* tempHi = Hi;
        ListNode* tempLo = Lo;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                tempLo->next = temp;
                temp = temp->next;
                tempLo = tempLo->next;
            }
            else{
                tempHi->next = temp;
                temp = temp->next;
                tempHi = tempHi->next;
            }
        }
        tempLo->next = Hi->next;
        tempHi->next = NULL;
        return Lo->next;
    }
};