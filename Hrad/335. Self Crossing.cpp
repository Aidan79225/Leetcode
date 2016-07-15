class point{
    private:
        int x,y;
    public:
        point(){}
        point(int x1,int y1){
            x=x1;
            y=y1;
        }
        void print(){
            cout<<"x : "<<x<<", y : "<<y<<endl;
        }
        void set(int x1,int y1){
            x=x1;
            y=y1;
        }
        int getX(){return x;}
        int getY(){return y;}
};
class Line{
    public:
        Line(){}
        point points[2];
        bool isVertical = false;
        void print(){
            cout<<"=============="<<endl;
            points[0].print();
            points[1].print();
            cout<<"isVertical : "<<isVertical<<endl;
            cout<<"=============="<<endl;
        }
        bool hasCrossPoint(Line l2){
            if(isVertical && l2.isVertical){
                if(points[0].getX() == l2.points[0].getX()){
                    if(isOnline(points[0],l2.points[0],l2.points[1]))return true;
                    if(isOnline(points[1],l2.points[0],l2.points[1]))return true;
                    if(isOnline(l2.points[0],points[0],points[1]))return true;
                    if(isOnline(l2.points[1],points[0],points[1]))return true;
                }
            }else if(isVertical && !l2.isVertical){
                point cross(points[0].getX(),l2.points[0].getY());
                if(isOnline(cross,l2.points[0],l2.points[1]))
                    if(isOnline(cross,points[0],points[1]))
                        return true;
            }else if(!isVertical && l2.isVertical){
                point cross(l2.points[0].getX(),points[0].getY());
                if(isOnline(cross,l2.points[0],l2.points[1]))
                    if(isOnline(cross,points[0],points[1]))
                        return true;
            }else if(!isVertical && !l2.isVertical){
                if(points[0].getY() == l2.points[0].getY()){
                    if(isOnline(points[0],l2.points[0],l2.points[1]))return true;
                    if(isOnline(points[1],l2.points[0],l2.points[1]))return true;
                    if(isOnline(l2.points[0],points[0],points[1]))return true;
                    if(isOnline(l2.points[1],points[0],points[1]))return true;
                }
            }
            return false;
        }
        
        bool isOnline(point target,point a,point b){
            if (target.getX() >= min(a.getX(), b.getX()) &&
                target.getX() <= max(a.getX(), b.getX()) &&
                target.getY() >= min(a.getY(), b.getY()) && 
                target.getY() <= max(a.getY(), b.getY()))
            return true;

            return false;
        }
        
        int min(int a,int b){
            if(a>b)return b;
            else return a;
        }
        int max(int a,int b){
            if(a<b)return b;
            else return a;
        }
};
class Solution {
public:
    int nX=0,nY=0;
    vector<Line> lines;
    bool isSelfCrossing(vector<int>& x) {
        getLines(x);
        for(int i=0;i<lines.size();i++){
            lines[i].print();
        }
        return findCross();
    }
    void getLines(vector<int>& x){
        for(int i =0 ;i<x.size();i++ ){
            Line line;
            line.points[0].set(nX,nY);
            switch( i % 4){
                case 0:
                    nY = nY + x[i];
                    line.isVertical = true;
                    break;
                case 1:
                    nX = nX - x[i];
                    break;
                case 2:
                    nY = nY - x[i];
                    line.isVertical = true;
                    break;
                case 3:
                    nX = nX + x[i];
                    break;
            }
            line.points[1].set(nX,nY);
            lines.push_back(line);
        }
    }
    bool findCross(){
        for(int i = 0; i <lines.size(); i++){
            for(int j = 0 ;j<lines.size();j++){
                if(abs(i-j)>1)
                if(lines[i].hasCrossPoint(lines[j]))return true;
            }
        }
        return false;
    }
    int abs(int a){
        if(a<0)return -a;
        else return a;
    }
};


