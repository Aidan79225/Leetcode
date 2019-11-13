class Solution {
    public int mctFromLeafValues1(int[] arr) {
        int ans = 0;
        ArrayList<Integer> a = new ArrayList<>();
        for (int t: arr) {
            a.add(t);
        }
        while(a.size() > 1) {
            int min = Integer.MAX_VALUE;
            int minIndex = 0;
            for (int i = 0; i < a.size()-1; i++) {
                int l = a.get(i);
                int r = a.get(i+1);
                int k = l*r;
                if (min > k) {
                    min = k;
                    minIndex = l > r ? i+1 : i;
                }
            }
            ans += min;
            a.remove(minIndex);
            // System.out.println(min + ", " + minIndex + ", " + a);
        }
        return ans;
    }
    
    public int mctFromLeafValues(int[] arr) {
        div(arr, 0, arr.length-1);
        return ans;
    }
    int ans = 0;
    public int div(int[] arr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return arr[l];
        }
        int maxIndex = l;
        for (int i = l;i <= r; i++) {
            if (arr[maxIndex] < arr[i]) {
                maxIndex = i;
            }
        }
        
        int lv = div(arr, l, maxIndex-1);
        int rv = div(arr, maxIndex+1, r);
        
        ans += arr[maxIndex]*(lv+rv);
        return arr[maxIndex];
    }
    
}

// [7,6,2,4,9,13,6,2]
// 7,6,4,9,13,6,2  8
// 7,6,4,9,13,6  20
// 7,6,9,13,6  44
// 7,9,13,6  86
// 9,13,6 149
// 9,13 227
// 344
