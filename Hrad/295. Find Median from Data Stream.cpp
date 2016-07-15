class MedianFinder {
public:
    vector<int> stack;
    // Adds a number into the data structure.
    void addNum(int num) {
        if(stack.size()==0){
            stack.push_back(num);
            return;
        }else{
            int left=0,right=stack.size()-1,mid=(left+right)/2;
            while(right>left){
                if(num>stack[mid]){
                    left =mid+1;
                }else{
                    right = mid;
                }
                mid=(left+right)/2;
            }
            if(num>stack[mid]){
                stack.insert(stack.begin()+mid+1,num);
            }else{
                stack.insert(stack.begin()+mid,num);
            }
            
        }
    }

    // Returns the median of current data stream
    double findMedian() {
    
        if(stack.size()%2 == 1){
            return (double)stack[(stack.size()-1)/2];
        }else{
            return ((double)stack[stack.size()/2 - 1 ] + (double)stack[stack.size()/2])/2.0;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
