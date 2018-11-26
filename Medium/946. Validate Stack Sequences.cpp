class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int popIndex = 0;
        stack<int> mStack;
        for (int i : pushed) {
            mStack.push(i);
            while(!mStack.empty() && mStack.top() == popped[popIndex]){
                mStack.pop();
                ++popIndex;
            }
        }
        return popIndex == popped.size();   
    }

};
