class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
       int max1=0,max2=0,max3=0; 
        max1 = s1.size();
        max2 = s2.size();
        max3 = s3.size();
        bool f[max1+1][max2+1] = {false};
        if(max1+max2 != max3)return false;
        f[0][0] = true;
        for(int i = 0; i < max1+1;i++){  
            for(int j = 0; j < max2+1; j++){  
                if(j > 0){  
                    f[i][j] = f[i][j-1]&&(s3[i+j-1] == s2[j-1]);  
                }  
                if(i > 0){  
                    f[i][j] = f[i][j] || ( f[i-1][j]&&(s3[i+j-1] == s1[i-1]));  
                }  
            }  
        }  
        return f[max1][max2]; 
        
    }
};
