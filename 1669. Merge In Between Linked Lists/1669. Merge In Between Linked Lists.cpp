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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        // Pointers to manage the positions in list1
        // pointer to track the node befort 'a' pos
        ListNode* previousNode = list1;
        // pointer to track the node at the 'b' pos
        ListNode* nextNode = list1;

        // Move the previousNode pointer to the node just before the node at pos 'a'
        for (int j = 1; j < a; ++j) {
            previousNode = previousNode->next;
        }

        // Move the nextNode pointer to the node at pos 'b'
        for (int j = 0; j <= b; ++j) {
            nextNode = nextNode->next;
        }

        // Attach the start of list2 to where  'a' was in list1
        previousNode->next = list2;

        // Traerse list2 until end
        while (previousNode->next) {
            previousNode = previousNode->next;
        }

        // Connect the end of list2 to the node just after 'b' in list1
        previousNode->next = nextNode;

        // @return modified list1 with list2 merged in between
        return list1;
    }
};