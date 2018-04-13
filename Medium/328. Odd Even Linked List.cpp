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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        ListNode* evenH = new ListNode(0);
        ListNode* evenC = evenH;
        while(temp){
            evenC -> next = temp -> next;
            evenC = evenC -> next;
            if(evenC){
                temp -> next = evenC -> next;
            }
            if(!temp -> next){
                temp -> next = evenH -> next;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
};
