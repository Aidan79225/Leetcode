class Solution {
public:
    int charToInt(char c){
        switch(c){
            case 'q':
                return 0;
            case 'w':
                return 1;
            case 'e':
                return 2;
            case 'r':
                return 3;
            case 't':
                return 4;
            case 'y':
                return 5;
            case 'u':
                return 6;
            case 'i':
                return 7;
            case 'o':
                return 8;
            case 'p':
                return 9;
            case 'a':
                return 10;
            case 's':
                return 11;
            case 'd':
                return 12;
            case 'f':
                return 13;
            case 'g':
                return 14;
            case 'h':
                return 15;
            case 'j':
                return 16;
            case 'k':
                return 17;
            case 'l':
                return 18;
            case 'z':
                return 19;
            case 'x':
                return 20;
            case 'c':
                return 21;
            case 'v':
                return 22;
            case 'b':
                return 23;
            case 'n':
                return 24;
            case 'm':
                return 25;
        }
        return 0;
    }
    bool isAnagram(string s, string t) {
        int sCount[26];
        for(int i=0;i<26;i++){
            sCount[i]=0;
        }
        for(int i=0;i<s.size();i++){
            sCount[charToInt(s[i])]++;
        }
        for(int i=0;i<t.size();i++){
            sCount[charToInt(t[i])]--;
        }
        for(int i=0;i<26;i++){
            if(sCount[i]!=0)
                return false;
        }
        return true;
    }
};
