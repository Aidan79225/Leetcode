class Solution {
public:
    string intToRoman(int num) {
        string ans ="";
        if(num - 1000 >= 0){
            ans = "M" + intToRoman(num -1000);
        }else if(num - 900 >= 0){
            ans = "CM" + intToRoman(num -900);
        }else if(num - 500 >= 0){
            ans = "D" + intToRoman(num -500);
        }else if(num - 400 >= 0){
            ans = "CD" + intToRoman(num -400);
        }else if(num - 100 >= 0){
            ans = "C" + intToRoman(num -100);
        }else if(num - 90 >= 0){
            ans = "XC" + intToRoman(num -90);
        }else if(num - 50 >= 0){
            ans = "L" + intToRoman(num -50);
        }else if(num - 40 >= 0){
            ans = "XL" + intToRoman(num -40);
        }else if(num - 10 >= 0){
            ans = "X" + intToRoman(num -10);
        }else if(num - 9 >= 0){
            ans = "IX" + intToRoman(num -9);
        }else if(num - 5 >= 0){
            ans = "V" + intToRoman(num -5);
        }else if(num - 4 >= 0){
            ans = "IV" + intToRoman(num -4);
        }else if(num - 1 >= 0){
            ans = "I" + intToRoman(num -1);
        }
        
        return ans;
    }
};
