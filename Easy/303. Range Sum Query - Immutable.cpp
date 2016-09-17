class NumArray {
public:
    int* table2;
    int size;

    NumArray(vector<int> &nums) {
        int size = nums.size();
        if(size != 0){
            table2 = (int*) malloc ((size+1)*sizeof(int));

            table2[0]=nums[0];
            for(int i=1;i<size;i++){
                table2[i] = table2[i-1] + nums[i]; 
            }
        }
        

    }

    int sumRange(int i, int j) {
        if(i<=0)return table2[j];
        return table2[j] - table2[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
