class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size();
        vector<int> temp(n,INT_MAX);
        vector<int> index(size,0);
        temp[0]=1;
        for(int i=1 ; i < n ; i++){
            for(int j=0 ; j<size ;j++){
                temp[i] = min(temp[i],temp[index[j]]*primes[j]);
            }
            for(int j=0 ; j<size ;j++){
                if(temp[i] == temp[index[j]]*primes[j]){
                    index[j]++;
                }
            }
            
        }
        return temp[n-1];
        
    }
};
