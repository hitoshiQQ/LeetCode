class MyQueue {
private:
    // Variables
    // Stack for enqueuing / dequeuing elements
    stack<int> inputStack;
    stack<int> outputStack;

    // Helper func to move elements from inputStack to outputStack
    void prepareOutputStack() {
        // Only move elements if outputStack is empty
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                // Move element to outputStack
                outputStack.push(inputStack.top());

                // Remove it from inputStack
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {

    }

    // Add an element to the back of the queue
    void push(int x) {
        inputStack.push(x);
    }

    // Removes the element from the front of the queue and ret its
    int pop() {
        prepareOutputStack();

        // Save the top element
        int element = outputStack.top();
        // Remove element from stack
        outputStack.pop();

        // Ret the saved element
        return element;
    }

    // Returns the element at the front of the queue without removing it
    int peek() {
        prepareOutputStack();
        return outputStack.top();
    }

    // Checks if the queue is empty
    bool empty() {
        // The queue is empty only if both stacks are empty
        return inputStack.empty() && outputStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */