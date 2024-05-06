class MyStack {
private:
    // This will act as the stack
    queue<int> mainQueue;

    // Used to reverse the order of elements in push operation
    queue<int> temporaryQueue;
public:
    MyStack() {
        // No init required as we're using STL queue 
    }

    // Push element X onto stack
    void push(int x) {
        temporaryQueue.push(x);

        // Reverse the order of elements by moving everything from mainQueue to temporaryQueue
        while (!mainQueue.empty()) {
            temporaryQueue.push(mainQueue.front());
            mainQueue.pop();
        }

        // Swap the names of mainQueue of mainQueue and temporaryQueue to reflect the change
        swap(mainQueue, temporaryQueue);
    }

    // Removes the elemen on top of the stack and returns that element
    int pop() {
        // Get the top element
        int topElement = mainQueue.front();

        // Remove the top element from the queue
        mainQueue.pop();

        // Return the popped element
        return topElement;
    }

    // Get the top element of the stack
    int top() {
        // The front of mainQueue is the top of stack
        return mainQueue.front();
    }

    // Returns true if the stack is empty, false otherwise
    bool empty() {
        // Check if the mainQueue is empty
        return mainQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */