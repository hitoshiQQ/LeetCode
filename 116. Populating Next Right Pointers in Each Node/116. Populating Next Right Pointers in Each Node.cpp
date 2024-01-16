/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        // node is above the current needling
        Node* node = root;

        while (node && node->left) {
            Node dummy(0); // before needling
            // needle children of the node

            for (Node* needle = &dummy; node; node = node->next) {
                needle->next = node->left;
                needle = needle->next;
                needle->next = node->right;
                needle = needle->next;
            }
            // Node move to next level
            node = dummy.next;
        }
        return root;
    }
};