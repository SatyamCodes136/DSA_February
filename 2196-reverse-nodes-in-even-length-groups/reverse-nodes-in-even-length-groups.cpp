class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        int groupSize = 1;

        while (curr) {
            ListNode* groupHead = curr;
            int count = 0;

            // count nodes in group
            while (curr && count < groupSize) {
                curr = curr->next;
                count++;
            }

            // if even → reverse this group
            if (count % 2 == 0) {
                ListNode* prevNode = curr;
                ListNode* node = groupHead;

                for (int i = 0; i < count; i++) {
                    ListNode* next = node->next;
                    node->next = prevNode;
                    prevNode = node;
                    node = next;
                }

                ListNode* temp = prev->next;
                prev->next = prevNode;
                prev = temp;
            } else {
                for (int i = 0; i < count; i++) {
                    prev = prev->next;
                }
            }

            groupSize++;
        }

        return dummy.next;
    }
};