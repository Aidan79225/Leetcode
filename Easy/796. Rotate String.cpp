class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length() != B.length()){
            return false;
        }
        string temp = A + A;
        int len = A.length();
        for(int i = 0 ; i <len ; i++){
            int j = 0;
            while(j < len){
                if(temp[i+j] == B[j]){
                    j++;
                }else{
                    break;   
                }
            }
            if(j == len){
                return true;
            }
        }
        return false;
    }
};
