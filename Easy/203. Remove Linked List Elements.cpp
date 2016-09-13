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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* position = head;
        ListNode* pre = NULL;
        while(position != NULL){
            if(position -> val == val){
                if(pre != NULL && position != head){
                    pre -> next = position -> next;
                }else{
                    head = position -> next;
                }
            }else{
                pre = position;
            }
            position = position -> next;
            
        }
        return head;
    }
};
