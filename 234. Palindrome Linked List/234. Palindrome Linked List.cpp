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
    bool isPalindrome(ListNode* head) {

        // Two pointers to find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Move fast by two and slow by one steps
        // when fast reaches end, slo will be at the middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* previousNode = nullptr;
        ListNode* currentNode = slow->next;

        while (currentNode) {

            ListNode* tmp_next = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = tmp_next;
        }

        // Compare the reversed second half with the first half
        while (previousNode) {

            // if the values are different, then it isn't a palindrome
            if (previousNode->val != head->val) {
                return false;
            }

            // Move to the next nodes in both halves
            previousNode = previousNode->next;
            head = head->next;
        }
        return true;
    }
};