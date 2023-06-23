class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int shift = 0;
        ListNode* res = new ListNode(0);
        ListNode* current = res;

        while (l1 || l2 || shift) {
            int d1 = l1 ? l1->val : 0;
            int d2 = l2 ? l2->val : 0;
            int sum = d1 + d2 + shift;
            current->next = new ListNode(sum % 10);
            current = current->next;
            shift = sum / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return res->next;
    }
};