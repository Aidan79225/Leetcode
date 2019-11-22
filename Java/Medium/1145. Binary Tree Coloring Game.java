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
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        TreeNode xNode = find(root, x);
        int l = getCount(xNode.left);
        int r = getCount(xNode.right);
        int p = n - l - r - 1;
        int max = Math.max(l, Math.max(r, p));
        return max > l + r + p - max;
    }
    
    TreeNode find(TreeNode root, int x) {
        if (root == null) {
            return null;
        }
        if (root.val == x) {
            return root;
        }
        TreeNode left = find(root.left, x);
        return left == null ? find(root.right, x) : left;
    }
    
    int getCount(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + getCount(root.left) + getCount(root.right);
    }
}
