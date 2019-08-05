/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        int[] mem = new int[1001];
        Arrays.fill(mem, -1);
        return find(root, mem);
    }
    
    public TreeNode find(TreeNode root, int[] mem) {
        int l = findDeepest(root.left, mem);
        int r = findDeepest(root.right, mem);
        if (l == r) {
            return root;
        } else if (l > r) {
            return find(root.left, mem);
        } else {
            return find(root.right, mem);
        }
    }
    
    private int findDeepest(TreeNode root, int[] mem) {
        if (root == null) {
            return 0;
        }
        if (mem[root.val] > 0) {
            return mem[root.val];
        }
        int ans = 1 + Math.max(findDeepest(root.left, mem), findDeepest(root.right, mem));
        mem[root.val] = ans;
        return ans;
    }
}
