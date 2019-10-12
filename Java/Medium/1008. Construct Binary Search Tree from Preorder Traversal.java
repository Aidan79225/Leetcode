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
    int i = 0;
    public TreeNode bstFromPreorder(int[] preorder) {
        i = 0;
        return getBst(preorder, -2147483648, 2147483647);
    }
    
    private TreeNode getBst(int[] preorder, int min, int max) {
        TreeNode cur = new TreeNode(preorder[i++]);
        if (i >= preorder.length) {
            return cur;
        }
        if (preorder[i] < cur.val) {
            cur.left = getBst(preorder, min, cur.val);
        } 
        if (i >= preorder.length) {
            return cur;
        }
        if (preorder[i] <= max) {
            cur.right = getBst(preorder, cur.val, max);
        }
        return cur;
    }
    
    
}
