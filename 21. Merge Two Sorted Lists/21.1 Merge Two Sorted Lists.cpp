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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // node - without allocating dynamic memory
        ListNode res(0);
        ListNode* current = &res;

        while (true) {

            //cut out cases with empty lists 
            if (l1 == nullptr && l2 == nullptr) {
                return res.next;
            }
            else if (l1 == nullptr) {
                current->next = l2;
                return res.next;
            }
            else if (l2 == nullptr) {
                current->next = l1;
                return res.next;
            }
            else {
                if (l1->val < l2->val) {
                    current->next = l1;
                    current = l1;
                    l1 = l1->next;
                }
                else {
                    current->next = l2;
                    current = l2;
                    l2 = l2->next;
                }
            }
        }
    }
};