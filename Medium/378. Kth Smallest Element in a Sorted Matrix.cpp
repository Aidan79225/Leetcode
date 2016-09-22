class Solution {
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
