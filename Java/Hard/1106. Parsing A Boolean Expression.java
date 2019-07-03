class Solution {
    int cur = 0;
    char[] expression;
    public boolean parseBoolExpr(String expression) {
        cur = 0;
        this.expression = expression.toCharArray();
        return eval();
    }
    
    private boolean eval() {
        switch(expression[cur]) {
            case 'f':
                cur++;
                return false;
            case 't':
                cur++;
                return true;
            case '!':
                return not();
            case '&':
                return and();
            case '|':
                return or();
            default :
                cur++;
                return eval();
        }
    }
    
    private boolean not() {
        cur += 2;
        boolean ans = !eval();
        cur++;
        return ans;
    }
    
    private boolean and() {
        boolean temp = true;
        cur += 2;
        while (expression[cur] != ')') {
            temp &= eval();
        }
        cur++;
        return temp;
    }
    
    private boolean or() {
        boolean temp = false;
        cur += 2;
        while (expression[cur] != ')') {
            temp |= eval();
        }
        cur++;
        return temp;
    }
}
