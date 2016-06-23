/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() <2)return points.size();
        vector<int> ans;
        double a,b;
        int count =0;
        for(int i = 0 ;i<points.size()-1;i++){          //兩個點形成的狀況
            for(int j = i+1;j<points.size();j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y){   //兩點重疊
                    count =0;
                    for(int k = 0;k<points.size();k++){
                    if(points[i].x == points[k].x && points[i].y == points[k].y){
                        count++;
                        }
                    }
                    ans.push_back(count);
                    continue;
                }
                else if(points[i].x == points[j].x){        //兩點X相等 斜率無限大
                    count =0;
                    for(int k = 0;k<points.size();k++){
                    if(points[i].x == points[k].x){
                        count++;
                        }
                    }
                     ans.push_back(count);
                     continue;
                }
                else{                                       //斜線 y=ax+b
                    a=(double)(points[i].y-points[j].y) / (double)(points[i].x-points[j].x) ;
                    b = (double)points[i].y - a * (double)points[i].x;
                    count = 2;
            
                    for(int k = 0;k<points.size();k++){
                        if(k==j || k==i)continue;
                        if(abs((double)points[k].y - a * (double)points[k].x - b) <0.00000001){
                            count++;
                        }
                    }
                    ans.push_back(count);    
                }
                
            }
        }
        
        
        count = 0;
        for(int i=0;i<ans.size();i++){
            if(count<ans[i])
                count = ans[i];
        }
        return count;
    }
    double abs(double n){
        if(n<0)return -n;
        return n;
    }
};
