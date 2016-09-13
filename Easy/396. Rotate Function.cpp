class Solution {
public:
    
    int maxRotateFunction(vector<int>& A) {
        int init =0,size = A.size(),max ,sum=0;
        for(int i=0;i<size;i++){
            init += i* A[i];
            sum += A[i];
        }
        max = init;

        for(int i=0;i<size;i++){
            init -= sum;
            init += (size) * A[i];
            if(max < init )max = init;    
        }
        
        return max;
        
    }
};
