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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* last = head;
        ListNode* current = head->next;

        while (current != NULL) {
            if (current->val == last->val) {
                //remove cur
                last->next = current->next;
            }
            else {
                //update last only if cur isn't duplicate
                last = current;
            }
            current = current->next;
        }
        return head;
    }
};