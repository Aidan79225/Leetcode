class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
        List<HashSet<Integer>> reds = new ArrayList<>(n);
        List<HashSet<Integer>> blues = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            reds.add(new HashSet<Integer>());
            blues.add(new HashSet<Integer>());
        }
        for (int[] re: red_edges) {
            reds.get(re[0]).add(re[1]);
        }
        for (int[] be: blue_edges) {
            blues.get(be[0]).add(be[1]);
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = -1;
        }
        bfs(ans, reds, blues);
        return ans;
    }
    
    private void bfs(int[] ans, List<HashSet<Integer>> reds, List<HashSet<Integer>> blues) {
        boolean[] hasAns = new boolean[ans.length];
        boolean[] visitedByRed = new boolean[ans.length];
        boolean[] visitedByBlue = new boolean[ans.length];
    
        
        Queue<Point> requests = new LinkedList();
        
        for (Integer i: blues.get(0)) {
            requests.offer(new Point(i, 1, false));
        }
        
        for (Integer i: reds.get(0)) {
            requests.offer(new Point(i, 1, true));
        }
        ans[0] = 0;
        hasAns[0] = true;
        visitedByRed[0] = true;
        visitedByBlue[0] = true;
        
        while(!requests.isEmpty()) {
            Point c = requests.poll();
            int length = c.length + 1;
                
            if (c.useRed && !visitedByRed[c.cur]) {
                visitedByRed[c.cur] = true;
                for (Integer i: blues.get(c.cur)) {
                   requests.offer(new Point(i, length, false));
                }
            } else if (!c.useRed && !visitedByBlue[c.cur]) {
                visitedByBlue[c.cur] = true;
                for (Integer i: reds.get(c.cur)) {
                    requests.offer(new Point(i, length, true));
                }
            }
            if (hasAns[c.cur]) {
                continue;
            }
            hasAns[c.cur] = true;
            ans[c.cur] = c.length;
        }
    }
    
    static class Point {
        int cur;
        int length;
        boolean useRed;
        Point(int cur, int length, boolean useRed) {
            this.cur = cur;
            this.length = length;
            this.useRed = useRed;
        }
    }
}
