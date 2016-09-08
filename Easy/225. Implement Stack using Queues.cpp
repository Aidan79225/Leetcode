class Stack {
public:
    // Push element x onto stack.
    vector<int> container;
    int i=0;
    void push(int x) {
        if(container.size()<= i )container.push_baack(x);
        else container[i] = x;
        i++;
    }

    // Removes the element on top of the stack.
    void pop() {
        container.pop_back();
        i--;
    }

    // Get the top element.
    int top() {
        return container[i-1];
    }

    // Return whether the stack is empty.
    bool empty() {
        return i==0;
    }
};
