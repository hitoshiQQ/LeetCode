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
    ListNode* doubleIt(ListNode* head) {
        // Reverse the input list to make it easier to handle carry operations
        head = reverse(head);

        // Create a dummy head to simplify the node inserion process
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        // Init multiplier to 2 for doubling the list values
        const int multiplier = 2;
        // Handle carry over during addition
        int carry = 0;

        // Traverse the reversed list, doubling each node's value
        while (head) {
            int product = head->val * multiplier + carry;
            carry = product / 10;
            current->next = new ListNode(product % 10);
            current = current->next;
            head = head->next;
        }

        // If there's a carry after the last multiplication, add a new node for it
        if (carry) {
            current->next = new ListNode(carry);
        }

        // Reverse the list again to restore the original order
        return reverse(dummy->next);
    }

    // Helper func to reverse a linked list
    ListNode* reverse(ListNode* head) {
        // Create a dummy head to simplify the node insertion process
        ListNode* dummy = new ListNode();
        ListNode* current = head;

        // Traverse the list and reverse the links
        while (current) {
            // Store next node
            ListNode* next = current->next;

            // Insert the current node at the beginning the reversed list
            current->next = dummy->next;
            dummy->next = current;

            // Move to the next node in the original list
            current = next;
        }
        return dummy->next;
    }
};