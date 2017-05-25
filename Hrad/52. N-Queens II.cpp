class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;   
        int t[n];
        for(int i =0;i<n;i++){
            t[i] = i;
        }
        p(ans,t,n,0);
        return ans;
    }
    void p(int& ans, int *t, int size,int head){
        if(head == size){
            if(check(t,size)){
                ans++;
            }  
            return;
        }
        for(int i=head;i<size;i++){
            swap(t,head,i);
            if(check(t,head)){
                p(ans,t,size,head+1);   
            }
            swap(t,head,i);
        }
    }
    bool check(int* t,int size){
        for(int i = 0; i<size-1;i++){
            for(int j = i+1 ;j<size;j++){
                if(abs(t[i] -t[j]) == j-i){
                    return false;
                }
            }
        }
        return true;
    }
    void swap(int* t,int a,int b){
        char c = t[a];
        t[a] = t[b];
        t[b] = c;
    }
};
