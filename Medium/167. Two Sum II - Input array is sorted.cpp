class Solution {
public:
    int findIndex(int l, int r, vector<int>& n , int t){
        if(n[l] == t)return l;
        if(n[r] == t)return r;
        int m = (r - l) / 2 + l; 
        if(m == l ){
            if(n[m] == t)return m;
            else return r;
        }
            
        if(n[m] < t){
            return findIndex(m,r,n,t);
        }else if(n[m] > t){
            return findIndex(l,m,n,t);
        }else{
            return m;
        }
    }
    vector<int> twoSum(vector<int>& n, int target) {
        vector<int> ans;
        int size = n.size();
        int temp;
        int j;
        for(int i=0 ; i<size-1;i++){
            temp = target - n[i];
            j =findIndex(i+1,size-1,n,temp);
            if(n[j] == temp){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
        }
        return ans;
    }
};
