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
    ListNode* reverseList(ListNode* head) {

        // The "dummy" node acts as the new head of the reverse list
        ListNode* dummy = new ListNode();

        // "current" node will traverse the original list
        ListNode* current = head;

        // Iterate throught the list until we reach the end
        while (current != nullptr) {

            // "next_node" temporarily stores the next node
            ListNode* next_node = current->next;

            // Reverse the "current" node's pointer to point to the new list
            current->next = dummy->next;

            // "current" node is prepended to the new list
            dummy->next = current;

            // Move to the next node in the original list
            current = next_node;
        }
        return dummy->next;
    }
};