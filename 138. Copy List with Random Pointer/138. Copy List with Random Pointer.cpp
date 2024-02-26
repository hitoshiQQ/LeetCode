/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (const auto iter = map.find(head); iter != map.cend()) {
            return iter->second;
        }

        Node* new_node = new Node(head->val);
        map[head] = new_node;
        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);
        return new_node;
    }

private:
    unordered_map<Node*, Node*> map;
};