class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        int t[n];
        for(int i =0;i<n;i++){
            t[i] = i;
        }
        p(ans,t,n,0);
        return ans;
    }
    void p(vector<vector<string>>& ans, int *t, int size,int head){
        if(head == size){
            if(check(t,size)){
                ans.push_back(convert(t,size)); 
            }  
            return;
        }
        //DFS
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
    vector<string> convert(int* t,int size){
        vector<string> ans;
        for(int i=0;i<size;i++){
            string temp = "";
            int indexQ = t[i];
            for(int j=0;j<size;j++){
                if(j == indexQ){
                    temp = temp + 'Q';
                }else{
                    temp = temp + '.';
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
    void swap(int* t,int a,int b){
        char c = t[a];
        t[a] = t[b];
        t[b] = c;
    }
};
