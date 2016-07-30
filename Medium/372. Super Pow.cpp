class Solution {
public:
    int getTenMod(int a,int n){
        int temp =1;
        for(int i =0;i<n;i++){
            temp = (temp*a) %1337;
        }
        return temp;
    }
    int superPow(int a, vector<int>& b) {
        a=a%1337;
        int ans=1,n=b.size()-1;
        for(int i = n ;i>=0;i-- ){
            
            ans= (ans*getTenMod(a,b[i]))%1337;
            a= getTenMod(a,10);
        }
        return ans;
    }
};
