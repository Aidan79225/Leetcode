class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        List<Engineer> eng = new ArrayList();
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            eng.add(new Engineer(speed[i], efficiency[i]));
        }
        Collections.sort(eng, (a, b)-> {
            return -a.efficiency+b.efficiency;
        });
        Queue<Integer> queue = new PriorityQueue<>();
        long sp = 0;
        for (Engineer e: eng) {
            if (queue.size() >= k) {
                sp -= queue.poll();
            }
            sp += e.speed;
            queue.add(e.speed);
            ans = Math.max(ans, sp * e.efficiency);
        }
        return (int)(ans % 1000000007);
    }
    
    class Engineer {
        int speed;
        int efficiency;
        Engineer(int speed, int efficiency) {
            this.speed = speed;
            this.efficiency = efficiency;
        }
    }
}
