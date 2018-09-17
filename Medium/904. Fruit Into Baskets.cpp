class Solution {
public:
    class Queue{
    public:
        queue<int> mQ;
        int x1=0, x2=0;
        int y1=0, y2=0;
        void insert(int v){
            if(x1 == 0){
                mQ.push(v);
                x1 = mQ.size();
                x2 = v;
                return;
            }
            if(v == x2){
                mQ.push(v);
                x1 = mQ.size();
                return;
            }
            
            
            if(y1 == 0){
                mQ.push(v);
                y1 = mQ.size();
                y2 = v;
                return;
            }
            if(v == y2){
                mQ.push(v);
                y1 = mQ.size();
                return;
            }
            
            if(v != y2 && v != x2){
                mQ.pop();
                y1--;
                x1--;
                insert(v);
            }
        }
        int size(){
            return mQ.size();
        }
    };
    int totalFruit(vector<int>& tree) {
        Queue mQ;
        int ans = 0;
        for(auto i : tree){
            mQ.insert(i);
            ans = max(ans, mQ.size());
        }
        
        return ans;
    }
};
