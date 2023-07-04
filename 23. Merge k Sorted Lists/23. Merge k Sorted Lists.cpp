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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };

        // create the queue &&  use minheap to add in head elements first
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (ListNode* j : lists) {
            if (j != nullptr) {
                pq.push(j);
            }
        }


        ListNode* h = new ListNode(-1);
        ListNode* current = h;

        // queue execution
        while (!pq.empty()) {
            ListNode* j = pq.top();
            pq.pop();
            current->next = j;
            j = j->next;
            current = current->next;
            current->next = nullptr;
            if (j != nullptr) {
                pq.push(j);
            }
        }
        return h->next;
    }
};