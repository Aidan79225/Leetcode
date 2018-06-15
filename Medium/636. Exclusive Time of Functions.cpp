class Solution {
public:
    class FunctionTime{
        public:
            int functionId = -1;
            int time = 0;
            int atTime = 0;
            FunctionTime(int functionId, int atTime){
                this -> functionId = functionId;
                this -> atTime = atTime;
            }
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<FunctionTime> mStack;
        vector<int> ans(n,0);
        for(string res : logs){
            vector<string> t = spilt(res, ':');
            int functionId = stoi(t[0]);
            string action = t[1];
            int atTime = stoi(t[2]);
            if(mStack.empty()){
                mStack.push(FunctionTime(functionId,atTime));
            }else{
                if(action == "end"){
                    ans[mStack.top().functionId] += mStack.top().time + atTime - mStack.top().atTime + 1;
                    mStack.pop();
                    if(!mStack.empty()){
                        mStack.top().atTime = atTime+1;   
                    }
                }else{
                    mStack.top().time += atTime - mStack.top().atTime;
                    mStack.push(FunctionTime(functionId,atTime));
                }
            }
        }
        return ans;
    }
    vector<string> spilt(string res, char c){
        vector<string> ans;
        int index = 0;
        int tLength = 0;
        while(index+tLength < res.length()){
            if(res[index+tLength] == c){
                ans.push_back(res.substr(index,tLength));
                index = index+tLength+1;
                tLength = 0;
            }else{
                tLength++;
            }
        }
        ans.push_back(res.substr(index,tLength));
        return ans;
    }
};
