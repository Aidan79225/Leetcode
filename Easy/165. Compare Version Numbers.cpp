class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0,j = 0,ii=0,jj=0,v1i,v2i;
        bool v1down = true,v2down = true;
        while(i<v1.size() || j<v2.size()){
            while(v1[i] != '.' && i<v1.size())i++;
            while(v2[j] != '.' && j<v2.size())j++;
            v1i = 0;
            v2i = 0;
            if(i<=v1.size() && ii <v1.size() && v1down){
                if(i == v1.size()){
                    v1down = false;
                }
                for(int ik = ii; ik<i  ;ik++){
                    v1i *= 10;
                    v1i += v1[ik]-'0';
                }    
            }
            
            if(j<=v2.size() && jj <v2.size() && v2down){
                if(j == v2.size()){
                    v2down = false;
                }
                for(int jk =  jj ; jk<j  ;jk++){
                    v2i *= 10;
                    v2i += v2[jk]-'0';
                }
            }
            if(v1i - v2i>0)return 1;
            else if(v1i - v2i<0)return -1;
            i++;
            j++;
            ii=i;
            jj=j;
        }
        return 0;
    }
};
