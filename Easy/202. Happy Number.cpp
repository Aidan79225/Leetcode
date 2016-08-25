class Solution {
public:
    
    int compute(int n){
        int ans = 0;
        for(;n>0;n /= 10){
            int a = n%10;
            ans += a*a;
        }
        return ans;
    }
    bool hasNum(vector<int> &hash,int n){
        for(int i=0;i<hash.size();i++){
            if(hash[i] == n)return true;
        }
        return false;
    }
    bool isHappy(int n) {
        vector<vector<int>> hash;
        hash.resize(47);
        const int max = 47;
        int temp ;
        while(1){
            temp = compute(n);
            if(temp == 1) return true;
            else if (hasNum(hash[n%max],temp)) return false;
            else{
                hash[n%max].push_back(temp);
            }
            n = temp;
        }
        return false;
    }
};
