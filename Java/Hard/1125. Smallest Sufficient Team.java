class Solution {
    HashMap<Integer, Node> nodes;
    int[] max;
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int[] lines = new int[people.size()];
        for (int i = 0; i < people.size(); i++) {
            int sk = 1;
            List<String> person = people.get(i);
            int j = 0;
            for (String skill : req_skills) {
                sk<<=1;
                if (j < person.size()) {
                    String psk = person.get(j);
                    if (psk.equals(skill)) {
                        sk |= 1;
                        j++;
                    }
                    
                }
            }
            lines[i] = sk;
        }
        dfs(1<<req_skills.length, 1<<req_skills.length, lines, new boolean[people.size()], 0, findDuplicated(lines));
        return max;
    }
    
    void dfs(int state, int checkBit, int[] lines, boolean[] users, int usersSize, boolean[] cannotUse) {
        if (max != null && usersSize >= max.length) {
            return;
        }
        
        if (checkBit == 0) {
            int[] array = new int[usersSize];
            int k = 0;
            for (int i = 0; i < users.length && k < usersSize; i++) {
                if (users[i]) {
                    array[k++] = i;
                }
            }
            max = array;
            return; 
        }
        if ((state&checkBit) > 0) {
            dfs(state, checkBit>>1, lines, users, usersSize, cannotUse);
        }
        for (int i =0; i<lines.length; ++i) {
            int line = lines[i];
            if (cannotUse[i]) {
                continue;
            }
            if (users[i]) {
                continue;
            }
            if ((line&checkBit) > 0) {
                users[i] = true;
                dfs(state|line, checkBit>>1, lines, users, usersSize+1, cannotUse);
                users[i] = false;
            }
        }
    }
    
    
    private boolean[] findDuplicated(int[] skill) {
        boolean[] out = new boolean[skill.length];
        for (int i = 0; i < skill.length; i++) {
            for (int j = i + 1; j < skill.length; j++) {
                if ((skill[i] & skill[j]) == Math.min(skill[i], skill[j])) {
                    out[(skill[i] > skill[j]) ? j : i] = true;
                }
            }
        }

        return out;
    }
    
    public int[] smallestSufficientTeam1(String[] req_skills, List<List<String>> people) {
        max = null;
        HashMap<String, Integer> indexMap = new HashMap<String, Integer>();
        for (int i = 0; i < req_skills.length; i++) {
            indexMap.put(req_skills[i], i);
        }
        int[][] matrix = new int[people.size()][req_skills.length];
        for (int i = 0; i < people.size(); i++) {
            List<String> person = people.get(i);
            for (String skill : person) {
                matrix[i][indexMap.get(skill)] = 1;
            }
        }
        List<Node> target = new ArrayList<Node>();
        nodes = new HashMap<Integer, Node>();
        for (String skill : req_skills) {
            target.add(new Node());
        }
        for (int j = 0; j < target.size(); j++) {
            Node c = target.get(j);
            c.j = j;
            if (j-1 >= 0) {
                c.l = target.get(j-1);
            }
            if (j+1 < target.size()) {
                c.r = target.get(j+1);
            }
            for (int i = 0; i < people.size(); i++) {
                if (matrix[i][j] == 1) {
                    Node n = getNode(i, j);
                    c.b = n;
                    n.t = c;
                    c = n;
                }
            }
        }
                
        for (int i = 0; i < matrix.length; i++) {
            Node c = null;
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 1) {
                    Node n = getNode(i, j);
                    if (c != null) {
                        c.r = n;
                        n.l = c;
                    }
                    c = n;
                }
            }
        }
        
        int[] lines = new int[people.size()];
        for (int i = 0; i < people.size(); i++) {
            int sk = 1;
            List<String> person = people.get(i);
            int j = 0;
            for (String skill : req_skills) {
                sk<<=1;
                if (j < person.size()) {
                    String psk = person.get(j);
                    if (psk.equals(skill)) {
                        sk |= 1;
                        j++;
                    }
                    
                }
            }
            lines[i] = sk;
        }
        
        start(target, new HashSet<Integer>(), new HashSet<Integer>(), findDuplicated(lines));
        return max;
    }
    void start(List<Node> target, Set<Integer> cur, Set<Integer> ans, boolean[] cannotUse) {
        if (max != null && ans.size() >= max.length) {
            return;
        }
        
        if (cur.size() == target.size()) {
            int[] array = new int[ans.size()];
            int k = 0;
            for (int i: ans)
                array[k++] = i;
            max = array;
            return; 
        }
        for (Node t : target) {
            if (cur.contains(t.j)) {
                continue;
            }
            Node c = t;
            while (c.b != null) {
                c = c.b;
                if (cannotUse[c.i]) {
                    continue;
                }
                ans.add(c.i);
                Node r = c;
                HashSet<Integer> added = new HashSet<Integer>();
                while (r != null) {
                    Node top = getTopest(r);
                    if (!cur.contains(top.j)) {
                        cur.add(top.j);
                        added.add(top.j);
                    }
                    r = r.r;
                }
                start(target, cur, ans, cannotUse);
                cur.removeAll(added);
                ans.remove(c.i);
            }
            break;
        }
    }
    
    Node getTopest(Node top) {
        while (top.t != null) {
            top = top.t;
        }
        return top;
    }
    
    Node getNode(int i, int j) {
        int key = (i<<5)+j;
        Node ans = nodes.get(key);
        if (ans == null) {
            ans = new Node(i,j);
            nodes.put(key, ans);
        }
        return ans;
    }
    
    static class Node {
        public int i = -1;
        public int j = -1;
        public Node() {
            
        }
        public Node(int i, int j) {
            this.i = i;
            this.j = j;
        }
        public Node l;
        public Node r;
        public Node t;
        public Node b;
        
        public String toString() {
            return String.format("i: %s, j: %s", i, j);
        }
    }
}
