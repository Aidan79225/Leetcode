class Solution {
    public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if (x1 <= x_center && x_center <= x2 && y1 <= y_center && y_center <= y2) {
            return true;    
        }
        
        
        
        if (y1 <= y_center && y_center <= y2) {
            if (x1-radius <= x_center && x_center <= x2+radius) {
                return true;    
            }
        }
        
        if (x1 <= x_center && x_center <= x2) {
            if (y1-radius <= y_center && y_center <= y2+radius) {
                return true;    
            }
        }
        
        
        
        int sr = radius*radius;
        
        
        int dx;
        int dy;
        
        
        dx = x1 - x_center;
        dy = y1 - y_center;
        if ( dx*dx+dy*dy <= sr) {
            return true;
        }
        
        dx = x2 - x_center;
        dy = y1 - y_center;
        if ( dx*dx+dy*dy <= sr) {
            return true;
        }
        dx = x1 - x_center;
        dy = y2 - y_center;
        if ( dx*dx+dy*dy <= sr) {
            return true;
        }
        dx = x2 - x_center;
        dy = y2 - y_center;
        if ( dx*dx+dy*dy <= sr) {
            return true;
        }
        return false;
    }
}
