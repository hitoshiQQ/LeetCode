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
    ListNode* reverseKGroup(ListNode* h, int k) {
        if(!h || !h->next || k == 1){
            return h;
        }

        // counter
        int j = 0;

        ListNode* tail = h;
        while(tail){
            j++;
            tail = tail->next;
        }
        // create and reverse
        ListNode *prev = nullptr, *next, *new_h;
        ListNode *t1 = nullptr, *t2 = h;
        tail = h;

        while(j >= k){

            // j - isn't multiple of k
            for(int i = 0;i< k;++i){
                next=tail->next;
                tail->next = prev;
                prev = tail;
                tail = next;
            }
            if(!new_h){
                new_h = prev;
            }
            if(t1){
                t1->next = prev;
            }
            t2->next = tail;
            t1 = t2;
            t2 = tail;
            prev = nullptr;
            j -= k;
        }
        return new_h;
    }
};