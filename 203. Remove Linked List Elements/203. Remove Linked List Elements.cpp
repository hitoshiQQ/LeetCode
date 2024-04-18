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
    ListNode* removeElements(ListNode* head, int val) {

        // Create a dummy node that serves the purpose of an anchor for the new list 
        // without the given value
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;

        // Init a pointer that will traverse the list, starting from the dummy node
        ListNode* current = dummyNode;

        // Iterate through the list until the end is reached
        while (current->next) {
            // Check if the next nodes value matches the value to be removed
            if (current->next->val == val) {
                // If a match is found, skip over the node with the matching value
                current->next = current->next->next;

            }
            else {
                // Otherwise, move to the next node
                current = current->next;
            }
        }
        return dummyNode->next;
    }
};