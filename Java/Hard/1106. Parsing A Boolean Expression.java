class Solution {
    public boolean parseBoolExpr(String expression) {
        return eval(expression.toCharArray(), 0, expression.length()-1);
    }
    
    private boolean eval(char[] expression, int cur, int end) {
        switch(expression[cur]) {
            case 'f':
                return false;
            case 't':
                return true;
            case '!':
                return !eval(expression, cur+2, end-1);
            case '&':
                return and(expression, cur, end);
            case '|':
                return or(expression, cur, end);
        }
        return false;
    }
    
    private boolean and(char[] expression, int cur, int end) {
        boolean temp = true;
        int c = cur;
        c += 2;
        while (c < end && expression[c] != ')') {
            int next = findEnd(expression, c);
            temp &= eval(expression, c, next);
            c = next+1;
            if (expression[c] == ',') {
                c++;
            }
        }
        return temp;
    }
    
    private boolean or(char[] expression, int cur, int end) {
        boolean temp = false;
        int c = cur;
        c += 2;
        while (c < end && expression[c] != ')') {
            int next = findEnd(expression, c);
            temp |= eval(expression, c, next);
            c = next+1;
            if (expression[c] == ',') {
                c++;
            }
        }
        return temp;
    }
        
    
    private int findEnd(char[] expression, int s) {
        switch(expression[s]) {
            case '|':
            case '!':
            case '&':
                s++;
                int t = 0;
                while(s < expression.length) {
                    switch(expression[s]) {
                        case '(':
                            t++;
                            break;
                        case ')':
                            t--;
                            break;
                    }
                    if (t == 0) {
                        return s;
                    }
                    s++;
                }
        }
        return s;
    }
}
