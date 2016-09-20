/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int size;
    ListNode* super;
    Solution(ListNode* head) {
        size =0;
        super = head;
        ListNode* temp = head;
        while(temp != NULL){
            size++;
            temp = temp -> next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* p = super;
        int index = rand() % size;
        int ans;
        for (int i = 0; i<index; i++, p = p->next) ;
        ans = p->val;
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
