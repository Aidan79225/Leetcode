class RLEIterator {
public:
    class Node{
    public:
        int val;
        int count;
        Node(int val, int count){
            this -> val = val;
            this -> count = count;
        }
        
    };
    queue<Node*> mQ;
    
    RLEIterator(vector<int> A) {
        int i = 0;
        while( i < A.size()){
            mQ.push(new Node(A[i+1], A[i]));
            i += 2;
        }
    }
    
    int next(int n) {
        if(mQ.empty()){
            return -1;
        }
        
        int t = n;
        while(t > 0 && !mQ.empty()){
            Node* node = mQ.front();
            int countT = node -> count;
            if(t > countT){
                mQ.pop();
                t = t - countT;
            }else{
                node -> count = countT - t;
                return node -> val;
            }
        }
        return -1;
        
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
