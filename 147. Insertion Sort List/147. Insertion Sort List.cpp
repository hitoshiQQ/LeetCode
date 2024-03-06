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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        // last && thus largest of the sorted list
        ListNode* prev = &dummy;

        // curent inserting node -> cache the next inserting node
        while (head != nullptr) {
            ListNode* next = head->next;

            // Move previous to the front
            if (prev->val >= head->val) {
                prev = &dummy;
            }

            while (prev->next && prev->next->val < head->val) {
                prev = prev->next;
            }

            // Update the current inserting node
            head->next = prev->next;
            prev->next = head;
            head = next;
        }
        return dummy.next;
    }
};