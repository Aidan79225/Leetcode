class Solution {
    class p{
        public: 
            int a;
            int b;
    };
public:
    void swap( p &a, p &b){
        p temp = a;
        a = b;
        b = temp;
    }
    int partition(vector<p> &a,int l,int r){
        p temp = a[r];
        int i = l-1;
        for(int j = l ;j < r;j++){
            if( a[j].b <= temp.b ){
                i++;
                swap(a[i],a[j]);
            }
        }
        swap(a[i+1],a[r]);
        return i+1;
    }
    void sortP(vector<p> &a,int l,int r){
        if(l<r){
            int q = partition(a,l,r);
            sortP(a,l,q-1);
            sortP(a,q+1,r);
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hashMap;
        map<int, int>::iterator iter;
        int size = nums.size();
        for(int i =0;i < size ;i++)
            hashMap[nums[i]]++;
        
        vector<p> a;
        for(iter = hashMap.begin(); iter != hashMap.end(); iter++){
            p temp;
            temp.a = iter->first;
            temp.b = iter->second;
            a.push_back(temp);
        }
        sortP(a,0,a.size()-1);
        
        vector<int> ans;
        for(int i = a.size()-1,j =0;j<k;j++,i--){
            ans.push_back(a[i].a);
        }
        return ans;
    }
};
