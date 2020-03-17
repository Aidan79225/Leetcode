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
    public TreeNode balanceBST(TreeNode root) {
        List<TreeNode> list = new ArrayList<>();
        addList(list, root);
        return getAVT(list, 0, list.size()-1);
    }
    
    void addList(List<TreeNode> list, TreeNode root) {
        if (root == null) {
            return;
        }
        addList(list, root.left);
        list.add(root);
        addList(list, root.right);
    }
    
    TreeNode getAVT(List<TreeNode> list, int l, int r) {
        if (r < l) {
            return null;
        }
        int m = (l + r) / 2;
        TreeNode root = list.get(m);
        root.left = getAVT(list, l, m-1);
        root.right = getAVT(list, m+1, r);
        return root;
    }
}
