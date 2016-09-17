class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
        if(n==3)return 1;
        int primes[(n+1)/2];
        // vector<int> primes;
        // primes.push_back(2);
        // primes.push_back(3);
        primes[0]=2;
        primes[1]=3;
        
        bool isPrime = true;
        int primesNum = 2;
        int sqry =1;
        for(int i = 5 ;i<n;i = i+2 ){
            isPrime = true;
            sqry = pow(i,0.5);
            for(int j = 1;j<primesNum && primes[j] <=sqry;j++){
                if(i % primes[j] == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                // primes.push_back(i);
                primes[primesNum] = i;
                primesNum++;
            }
            
        }
        return primesNum;
    }
};
