/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
    * @brief Method deletes the given node (except the tail) from the linked list
    * This function assumes that the node to delete is not the tail
    * and that we are not handling edge cases where node could be null
    * @param node - Represents the node to be deleted
    */
    void deleteNode(ListNode* node) {
        // Copy the value from the next node to the current node
        node->val = node->next->val;

        // Save the next->next node, which will be the new next after deletion
        ListNode* next_next = node->next->next;

        // Delete the next node, effectively removing it from the list
        delete node->next;

        // Make the next pointer of the current node point to the new next node
        node->next = next_next;
    }
};