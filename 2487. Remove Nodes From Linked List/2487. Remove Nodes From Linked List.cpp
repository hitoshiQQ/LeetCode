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
    ListNode* removeNodes(ListNode* head) {
        // This will hold the values of the nodes of the linked list
        vector<int> values;

        // Traverse the linked list and fill the vector with node values
        while (head) {
            values.emplace_back(head->val);
            head = head->next;
        }

        // This is used to keep track of the nodes to keep
        vector<int> stack;

        // Iterate over the values and use the stack to filter the values
        for (int value : values) {
            // If the last value in the stack is less than the current value, pop from stack
            while (!stack.empty() && stack.back() < value) {
                stack.pop_back();
            }

            // Push the current value onto the stack
            stack.push_back(value);
        }

        // Create a dummy node to build the new linked list
        ListNode* dummy_head = new ListNode();
        // Pointer to iterate through the new list
        ListNode* current = dummy_head;

        // COnstruct the new linked list from the stack values
        for (int value : stack) {
            current->next = new ListNode(value);
            current = current->next;
        }
        return dummy_head->next;
    }
};