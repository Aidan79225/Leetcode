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
        }
        if(head1==nullptr)   head->next=head2;
        if(head2==nullptr)   head->next=head1; 
        return ans.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode ans(0);
        if(lists.size() == 0 )
            return ans.next;
        int shift = 1,target = 1;
        while(target < lists.size()){
            target = target<<1;
            shift = shift<<1;
        }
        target = target>>1;
        shift = shift>>1;
        while(target != 0){
            for(int i =0;i<target;i++){
                if( i + shift <lists.size()){
                    lists[i] = mergeTwoLists(lists[i],lists[i+shift]);
                }
            }
            target = target>>1;
            shift = shift>>1;
        }
        
        return lists[0];
        
    }
};
