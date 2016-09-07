class Queue {
public:
    vector<int> ans;
    int i=0;
    // Push element x to the back of queue.
    void push(int x) {
        ans.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        i++;
    }

    // Get the front element.
    int peek(void) {
        return ans[i];
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return ans.size()==i;
    }
};
