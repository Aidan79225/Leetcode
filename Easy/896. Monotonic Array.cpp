class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() <= 2)return true;
        int temp = 0;
        for(int i = 1; i < A.size(); ++i){
            if(temp == 0){
                int key = A[i] - A[i-1];
                if(key != 0){
                    temp = key;
                }
            }else{
                break;
            }
        }
        bool isIncrease = temp > 0;
        
        if(isIncrease){
            for(int i = 1; i < A.size(); ++i){
                if(A[i] - A[i-1] < 0)return false;
            }
        }else{
            for(int i = 1; i < A.size(); ++i){
                if(A[i] - A[i-1] > 0)return false;   
            }
        }
        return true;
    }
};
