class Solution {
public:
    int bitCount(int n){
        int ans =0;
        while(n > 0){
            if(n & 0b1 == 1){
                ans++;
            }        
            n = n >> 1;
        }

        return ans;
    }
    string format(int h, int m){
        string a ="";
        char c;
        if(h > 9){
            a += '1';
            c = h - 10 + '0';
        }else{
            c = h +'0';
        }
        
        a += c;
        a += ':';
        c = m /10 +'0';
        a += c;
        c = m % 10 + '0';
        a += c;
        return a;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        for (int h=0; h<12; h++)
            for (int m=0; m<60; m++)
                if (bitCount(h * 64 + m) == num)
                    times.push_back(format( h, m));
        return times;    
    }
};
