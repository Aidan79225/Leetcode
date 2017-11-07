class Solution2 {
public:
    void merge(vector<int>& target,vector<int> key){
        int i=0;
        vector<int>::iterator it = target.begin();
        for(int j=0;j<key.size();j++){
            
            while(i < target.size() && target[i] < key[j])i++;
            target.insert(it+i,key[j]);
            i++;
        }
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int width = matrix.size();
        k--;
        matrix[0].reserve(width * width);
        for(int i=1;i<width;i++){
            merge(matrix[0],matrix[i]);
        }
        return matrix[0][k];
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0];
        int r = matrix[matrix.size()-1][matrix[0].size()-1]+1;
        while(l < r){
            int count = 0;
            int mid = l + (r-l)/2;
            for(int i = 0 ; i < matrix.size() ; i++){
                int j = matrix[i].size()-1;
                while(j >= 0 && matrix[i][j] > mid) j--;
                    count += (j + 1);
            }
            if(count < k){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};
