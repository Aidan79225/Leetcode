class Solution {
public:
    int ans = 0;
    int minSwapsCouples(vector<int>& row) {
        while(isNotConform(row)){
            int index = findFirst(row);
            if(index == -1)break;
            int x = ((row[index] >> 1)<< 1);
            int temp = x + 1 - (row[index] % 2 );
            int a = findTarget(row, temp);
            if(a == -1)break;
            swap(row[index+1],row[a]);
        }
        return ans;
    }
    int findFirst(vector<int>& row){
        for(int i = 0 ; i < row.size() ; i += 2){
            if((row[i]>>1) != (row[i+1]>>1)  ) {
                return i;
            }
        }
        return -1;
    }
    int findTarget(vector<int>& row , int t){
        for(int i = 0 ; i < row.size() ; i++){
            if(row[i] == t){
                 return i;
            }
        }
        return -1;
    }
    bool isNotConform(vector<int>& row){
        for(int i = 0 ; i < row.size() ; i += 2){
            if((row[i]>>1) != (row[i+1]>>1)  ) {
                return true;
            }
        }
        return false;
    }
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
        ans++;
    }
};
