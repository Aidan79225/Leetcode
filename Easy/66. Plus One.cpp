class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n == 0 ){
            digits.push_back(1);
            return digits;
        }
        digits[n-1]  += 1;
        for(int i = n-1;i >= 0;i--){
            int temp = digits[i];
            digits[i] = temp % 10;
            temp = temp /10;
            if(temp >0){
                if(i-1 >= 0)
                    digits[i-1] += temp;
                else{
                    vector<int>::iterator it = digits.begin();
                    digits.insert(it,temp);
                }
            }
        }
        return digits;
    }
};
