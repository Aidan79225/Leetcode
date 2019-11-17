class Solution {
    public String alphabetBoardPath(String target) {
        StringBuilder sb = new StringBuilder();
        char now = 'a';
        for (int i = 0; i < target.length(); ++i) {
            char c = target.charAt(i);
            int nx = getX(now);
            int ny = getY(now);
            int cx = getX(c);
            int cy = getY(c);
            
            int dx = nx - cx;
            int dy = ny - cy;
            while (dy > 0) {
                sb.append('L');
                --dy;
            }
            while (dx > 0) {
                sb.append('U');
                --dx;
            }
            while (dx < 0) {
                sb.append('D');
                ++dx;
            }
            while (dy < 0) {
                sb.append('R');
                ++dy;
            }
            sb.append('!');
            now = c;
        }
        return sb.toString();
    }
    
    private int getX(char a) {
        return (a - 'a') / 5;
    }
    
    private int getY(char a) {
        return (a - 'a') % 5;
    }
}
