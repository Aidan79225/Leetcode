class Solution {
public:
    string originalDigits(string s) {
        int table[26] = {0}; 
        for(char c : s){
            table[c - 'a']++;
        }
        int ans[10] = {0};
        ans[0] = table['z' - 'a']; //zero
        ans[2] = table['w' - 'a']; //two
        ans[4] = table['u' - 'a']; //four
        ans[6] = table['x' - 'a']; //six
        ans[8] = table['g' - 'a']; //eight
        ans[1] = table['o' - 'a'] - ans[0] - ans[2] - ans[4]; //one
        ans[3] = table['t' - 'a'] - ans[2] - ans[8]; //three
        ans[5] = table['f' - 'a'] - ans[4]; //five
        ans[7] = table['s' - 'a'] - ans[6]; //seven
        ans[9] = table['i' - 'a'] - ans[6] - ans[8] - ans[5]; //nine
        string a = "";
        for(int j = 0 ; j < 10; j++){
            for(int i = 0 ; i < ans[j] ; i++){
                a += ('0' + j);
            }
        }
    
        return a;
    }
    
};
