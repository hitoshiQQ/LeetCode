/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {

private:
    // Variables
    std::stack<TreeNode*> nodeStack;

public:
    // Constructor initializes the iterator using the root of binary search tree
    BSTIterator(TreeNode* root) {
        // Go all the way to the left-most node
        while (root != nullptr) {

            nodeStack.push(root);
            root = root->left;
        }
    }

    int next() {
        // The top element of the stack is the next smallest element
        TreeNode* currentNode = nodeStack.top();
        nodeStack.pop();

        // If there is a right subtree, push all left-most nodes of the subtree the stack
        TreeNode* node = currentNode->right;
        while (node != nullptr) {
            nodeStack.push(node);
            node = node->left;
        }

        // Return the value of the next smallest element
        return currentNode->val;
    }

    bool hasNext() {
        // If the stack is a empty, there is a next element
        return !nodeStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */