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
    ListNode* rotateRight(ListNode* head, int k) {

        // base case's
        if (!head || !head->next || k == 0) {
            return head;
        }

        int length = 1;
        ListNode* tail;

        // whirl the list, starting at the tail
        for (tail = head; tail->next; tail = tail->next) {
            ++length;
        }
        tail->next = head;


        // let's go from the middle, twist it by announcing a new index of the beginning.
        const int mid = length - k % length;
        for (int j = 0; j < mid; ++j) {
            tail = tail->next;
        }
        ListNode* _head = tail->next;
        tail->next = nullptr;

        return _head;
    }
};