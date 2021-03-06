/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} t1
 * @param {TreeNode} t2
 * @return {TreeNode}
 */
var mergeTrees = function(t1, t2) {
    if(t1 === null && t2 !== null){
        return t2;
    }else if(t1 !== null && t2 === null){
        return t1;
    }else if(t1 === null && t2 === null){
        return null;
    }
    t1.val = (t1.val ? t1.val : 0)  + (t2.val ? t2.val : 0);
    t1.left = mergeTrees(t1.left,t2.left);
    t1.right = mergeTrees(t1.right,t2.right);
    return t1;
};
