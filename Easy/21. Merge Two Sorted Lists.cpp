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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ans(0);
        ListNode* head;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        head = &ans;
        while(head1 != NULL && head2 != NULL){
            if(head1->val < head2->val){
                head->next = head1;
                head1 = head1->next;
            }else{
                head->next = head2;
                head2 = head2->next;
            }
            head = head->next;
            cout<<head->val<<endl;
        }
        if(head1==nullptr)   head->next=head2;
        if(head2==nullptr)   head->next=head1; 
        return ans.next;
    }
    
};
