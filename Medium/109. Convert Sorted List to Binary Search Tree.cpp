/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //Space : O(1), Time : O(n)
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr){
            count++;
            temp = temp -> next;
        }
        return sortedListToBST(head,0,count);
    }
    

    TreeNode* sortedListToBST(ListNode*& head, int start, int end) {
        if(head == nullptr)return nullptr;
        if(start > end) return nullptr;
        int mid = start + (end - start)/2;
        TreeNode* left = sortedListToBST(head, start,mid-1);
        TreeNode* root = new TreeNode(head -> val);
        head = head -> next;
        TreeNode* right = sortedListToBST(head, mid+1, end);
        root -> left =left;
        root -> right = right;
        return root;
    }
    
    
    
};
