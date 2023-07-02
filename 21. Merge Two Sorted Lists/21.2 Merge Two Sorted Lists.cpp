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
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        // if the list l1 ne smaller
        ListNode* h, * curr_1, * curr_2;

        if (l1->val <= l2->val) {
            h = curr_1 = l1;
            curr_2 = l2;
        }
        else {
            h = curr_1 = l2;
            curr_2 = l1;
        }

        if (curr_1->next == nullptr) {
            curr_1->next = curr_2;
            return curr_1;
        }


        // stopped when 1 list is ends
        while (curr_1 != nullptr && curr_2 != nullptr) {
            if (curr_1->next == nullptr) {
                curr_1->next = curr_2;

                // list became is empty
                curr_1 = nullptr;
            }
            else if (curr_2->val <= curr_1->next->val) {
                ListNode* temp = curr_1->next;
                curr_1->next = curr_2;
                curr_2 = curr_2->next;
                curr_1->next->next = temp;
            }
            else {
                curr_1 = curr_1->next;
            }
        }
        return h;
    }
};