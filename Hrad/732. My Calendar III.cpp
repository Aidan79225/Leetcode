class MyCalendarThree {
    public:
        class Node {
            public:
                Node *left;
                Node *right;
                int count = 0;
                int x= 0;
                int y = 0;
                int mid = -1;
                Node(int x,int y, int count ){
                    this -> x = x;
                    this -> y = y;
                    this -> count = count;
                    this -> mid = -1;
                }
        };
    
        MyCalendarThree() {
            this -> root = new Node(0,1000000000,0);
        }
    
        int book(int start, int end) {
            add(start,end,root);
            return ans;
        }
    private:
        Node* root;
        void add(int start, int end, Node* root){
            if(root -> mid != -1){
                if(start >= root -> mid){
                    add(start, end, root -> right);
                }else if(end <= root -> mid){
                    add(start, end, root -> left);
                }else{
                    add(start, root -> mid , root -> left);
                    add(root -> mid , end, root -> right);
                }
            }else{
                if(start == root -> x && end == root -> y){
                    root -> count++;
                    ans = max(ans, root -> count);
                }else if(start == root -> x){
                    root -> mid = end;
                    root -> left = new Node(root -> x, root -> mid, root -> count + 1);
                    root -> right = new Node(root -> mid, root -> y, root -> count);
                    ans = max(ans,root -> count + 1);
                }else if(end == root -> y){
                    root -> mid = start;
                    root -> left = new Node(root -> x, root -> mid, root -> count);
                    root -> right = new Node(root -> mid, root -> y, root -> count + 1);
                    ans = max(ans,root -> count + 1);
                }else{
                    root -> mid = start;
                    root -> left = new Node(root -> x, root -> mid, root -> count);
                    root -> right = new Node(root -> mid, root -> y, root -> count);
                    add(start,end, root -> right);
                }
                
            }
        }
        int ans = 0;
};
