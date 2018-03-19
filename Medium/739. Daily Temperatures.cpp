class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans;
        ans.resize(t.size());
        vector<int> mStack;
        int top = -1;
        mStack.resize(t.size());
        for(int i = 0 ; i < t.size() ; ++i){
            while(top != -1 && t[i] > t[mStack[top]]){
                int index = mStack[top--];
                ans[index] = i - index;
            }
            mStack[++top] = i;
        }
        return ans;
    }
    
    vector<int> dailyTemperatures1(vector<int>& t) {
        vector<int> ans;
        ans.resize(t.size());
        unordered_map<int,int> mMap;
        for(int i = t.size()-1 ; i >= 0 ; --i){
            mMap[t[i]] = i;
            ans[i] = max(0, findMin(mMap, t[i]) - i);
        }
        return ans;
    }
    int findMin(unordered_map<int,int>& mMap, int key){
        int min = INT_MAX;
        for(auto& it : mMap){
            if(it.first > key && min > it.second){
                min = it.second;
            }
        }
        return min == INT_MAX ? 0 : min;
    }
};
