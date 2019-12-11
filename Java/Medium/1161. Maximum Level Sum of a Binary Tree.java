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
    public int maxLevelSum(TreeNode root) {
        int level = 1;
        Queue<TreeNode> nodes = new LinkedList<>();
        Queue<TreeNode> nextNodes = new LinkedList<>();
        int maxSum = Integer.MIN_VALUE;
        int maxLevel = 0;
        TreeNode t;
        int curSum = 0;
        if (root != null) {
            nodes.offer(root);
        }
        
        while(!nodes.isEmpty()) {
            while ((t = nodes.poll()) != null) {
                if (t.left != null) {
                    nextNodes.offer(t.left);
                }

                if (t.right != null) {
                    nextNodes.offer(t.right);
                }
                curSum += t.val;
            }
            if (curSum > maxSum) {
                maxLevel = level;
                maxSum = curSum;
            }
            Queue<TreeNode> tt = nextNodes;
            nextNodes = nodes;
            nodes = tt;
            
            curSum = 0;
            ++level;
        
        }

        
        return maxLevel;
    }
}
