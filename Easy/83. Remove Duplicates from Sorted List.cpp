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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp =  head;
        while(temp!=NULL && (temp->next!=NULL)){
            if(temp->val == temp->next->val){
                ListNode* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};
