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
    ListNode* swapPairs(ListNode* head) {
        ListNode* first = head;
        ListNode* second;
        
        ListNode* zero = new ListNode(0);
        ListNode* ans = zero;
        ans ->next = head;
        ListNode* third;
        while(first != NULL){
            second = first ->next;
            if(second ==NULL)break;
            
            third = second -> next;
            second -> next = first;
            first -> next = third;
            zero -> next = second;
            
            zero = first;
            first = third;
            
        }
        return ans->next;
    }
};
