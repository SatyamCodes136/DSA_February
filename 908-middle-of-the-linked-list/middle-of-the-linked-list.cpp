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
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        //calculate the len of LL
        while(temp->next != NULL){
            n++;
            temp = temp->next;
        }

        temp = head;
        for(int i = n/2; i < n; i++){
            temp = temp->next;
        }
        return temp;
    }
};