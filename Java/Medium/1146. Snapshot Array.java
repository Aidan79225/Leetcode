class SnapshotArray {
    int snapId = 0;
    List<TreeMap<Integer, Integer>> array;
    public SnapshotArray(int length) {
        array = new ArrayList<>(length);
        for (int i = 0; i < length; i++) {
            array.add(new TreeMap<Integer, Integer>());
        }
    }
    
    public void set(int index, int val) {
        TreeMap<Integer, Integer> i = array.get(index);
        if (i == null) {
            i = new TreeMap<Integer, Integer>();
            array.set(index, i);
        }
        i.put(snapId, val);
    }
    
    public int snap() {
        return snapId++;
    }
    
    public int get(int index, int snapId) {
        TreeMap<Integer, Integer> i = array.get(index);
        if (i == null) {
            return 0;
        }
        Map.Entry<Integer, Integer> e = i.floorEntry(snapId);
        if (e == null) {
            return 0;
        }
        Integer ans = e.getValue();
        if (ans == null) {
            return 0;
        }
        return ans;
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */
