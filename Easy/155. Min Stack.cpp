class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    int index =0;
    int min = 2147483647;
    MinStack() {
        
    }
    
    void push(int x) {
        if(min > x)min = x;
        if(stack.size() <= index){
            stack.push_back(x);
        }else{
            stack[index] = x;
        }
        index++;
    }
    
    void pop() {
        index--;
        if(stack[index] == min){
            min = 2147483647;
            for(int i=0;i<index;i++){
                if(min > stack[i]){
                    min = stack[i];
                }
            }    
        }
        
    }
    
    int top() {
        return stack[index-1];
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
