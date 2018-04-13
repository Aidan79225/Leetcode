class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int size = arr.size();
        int p = 0;
        int mx = arr[p];
        while(p < size){
            ans++;
            for(int i = p ; i <= mx ; i++){
                if(arr[i] > mx){
                    mx = arr[i];
                }
            }
            p = mx+1;
            mx = arr[p];
        }
        return ans;
    }
    
};
