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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size =1;
        while(temp->next != NULL ){
            temp = temp->next;
            size ++;
        }
        if((size - n) == 0)return head->next;
        temp = head;
        for(int i=0;i<size - n-1;i++){
            temp = temp->next;
        }
        temp->next=temp->next->next;
        return head;
        
    }
};
