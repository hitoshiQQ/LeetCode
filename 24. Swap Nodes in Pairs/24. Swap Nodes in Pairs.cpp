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
    ListNode* swapPairs(ListNode* h) {
        if (h == nullptr || h->next == nullptr) {
            return h;
        }

        // ñreate a resulting res list that initially contains one dummy node
        ListNode* res = new ListNode(0);
        res->next = h;

        // ñreate a pointer to the current list
        ListNode* p = res;

        // go as long as there are at least 2 elements behind the pointer
        while (p->next != nullptr && p->next->next != nullptr) {
            ListNode* t1 = p->next;
            ListNode* t2 = p->next->next;
            ListNode* t3 = p->next->next->next;

            // swap the elements of the list 
            p->next = t2;
            t2->next = t1;
            t1->next = t3;
            p = p->next->next;
        }
        return res->next;
    }
};