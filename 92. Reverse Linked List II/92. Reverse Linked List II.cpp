class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n)
            return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        for (int j = 0; j < m - 1; ++j)
            prev = prev->next;  // Point to the node before the sublist [m, n]

        ListNode* tail = prev->next;  // Will be the tail of the sublist [m, n]

        // Reverse the sublist [m, n] one by one
        for (int j = 0; j < n - m; ++j) {
            ListNode* cache = tail->next;
            tail->next = cache->next;
            cache->next = prev->next;
            prev->next = cache;
        }

        return dummy.next;
    }
};